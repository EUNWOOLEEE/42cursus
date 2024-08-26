#include "../core/core.hpp"

Server::Server(int event_list_size, size_t _worker_connections) : worker_connections(_worker_connections),	\
																cur_connection(0),							\
																event_type_listen("listen"),				\
																event_type_client("client"),				\
																event_type_cgi("cgi") {
	event_queue = kqueue();
	if (event_queue == -1)
		throw Exception(EVENT_FAIL_CREATE_KQ);
	event_list.resize(event_list_size);
	kevent_timeout.tv_sec = 5;
	kevent_timeout.tv_nsec = 0;
}

Server::~Server(void) {
	for (unsigned int i = 0; i < listen_socket_list.size(); i++)
		close(listen_socket_list[i]);
	close(event_queue);
}

int						Server::getEventQueue(void) const { return event_queue; }
std::vector<uintptr_t>&	Server::getListenSocketList(void) { return listen_socket_list; }
int						Server::getCurConnection(void) const { return cur_connection; }
Client&					Server::getClient(uintptr_t socket) { return clients[socket]; }
std::vector<Client*>&	Server::getReadTimeoutList(void) { return read_timeout_list; }
std::vector<Client*>&	Server::getCGITimeoutList(void) { return cgi_timeout_list; }
kevent_t&				Server::getEventOfList(int idx) { return event_list[idx]; }
char*					Server::getEventTypeListen(void) { return event_type_listen; }
char*					Server::getEventTypeClient(void) { return event_type_client; }
char*					Server::getEventTypeCgi(void) { return event_type_cgi; }

void Server::addEvent(uintptr_t ident, int16_t filter,		\
						uint16_t flags,	size_t fflags,		\
						intptr_t data, void* udata) {
	kevent_t	temp;

	EV_SET(&temp, ident, filter, flags, fflags, data, udata);
	kevent(event_queue, &temp, 1, NULL, 0, NULL);
}

size_t Server::pollingEvent() {
	int	new_events;

	new_events = kevent(event_queue, NULL, 0, &event_list[0], event_list.size(), &kevent_timeout);

	if (new_events == -1)
		throw Exception(EVENT_FAIL_KEVENT);
	return new_events;
}

bool Server::checkErrorFlag(kevent_t& kevent) {
	if ((kevent.flags & EV_EOF && kevent.filter != EVFILT_PROC)	|| kevent.flags & EV_ERROR) {
		disconnectClient(kevent.ident);
		return true;
	}
	return false;
}

void Server::prepConnect(std::vector<ServerBlock>& server_blocks) {
    sockaddr_in	server_addr;
    int			new_listen_socket;

	for (unsigned long i = 0; i < server_blocks.size(); i++) {
		for (unsigned long j = 0; j < i; j++)
            if (server_blocks[j].getPort() == server_blocks[i].getPort())
                continue;

        new_listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (new_listen_socket == -1)
            throw Exception(EVENT_FAIL_CREATE_SOCKET);
        listen_socket_list.push_back(new_listen_socket);

        std::memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(server_blocks[i].getPort());
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

		// socket timeout 설정
        // int     optval = 1;
        // setsockopt(new_listen_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

        if (bind(new_listen_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(sockaddr_in)) == -1)
            throw Exception(EVENT_FAIL_BIND);
        if (listen(new_listen_socket, LISTEN_QUEUE_SIZE) == -1)
            throw Exception(EVENT_FAIL_LISTEN);
        if (fcntl(new_listen_socket, F_SETFL, O_NONBLOCK) == -1)
            throw Exception(EVENT_FAIL_FCNTL);
        addEvent(new_listen_socket, EVFILT_READ, EV_ADD, 0, 0, &event_type_listen);
    }
}

void Server::acceptNewClient(int listen_socket) {
	size_t	client_socket;

	if (cur_connection < worker_connections) {
		if ((client_socket = accept(listen_socket, NULL, NULL)) == -1) {
			eventException(EVENT_FAIL_ACCEPT, 0);
			return ;
		}

		if (fcntl(client_socket, F_SETFL, O_NONBLOCK) == -1) {
			close(client_socket);
			eventException(EVENT_FAIL_FCNTL, 0);
			return ;
		}
		addEvent(client_socket, EVFILT_READ, EV_ADD, 0, 0, &event_type_client);
		cur_connection++;
	}
	else {
		eventException(EVENT_CONNECT_FULL, 0);
	}
}

int Server::recieveFromClient(Client& client) {
	uintptr_t		client_socket = client.get_client_soket();
	std::string&	request_msg = client.get_request_instance().get_request_msg();
	char			buf[BUF_SIZE] = {0,};
	size_t			recieve_size;
	size_t			header_end;
	size_t			content_length;

	if ((recieve_size = recv(client_socket, buf, BUF_SIZE - 1, 0)) <= 0) {
		disconnectClient(client_socket);
		eventException(EVENT_FAIL_RECV, client_socket);
		return -1;
	}
	request_msg += buf;
	header_end = request_msg.find ("\r\n\r\n");

	if (header_end == std::string::npos) {
		client.get_timeout_instance().setSavedTime();
		return false;
	}

	if (request_msg.find("POST") == 0 && request_msg.find ("100-continue") == std::string::npos) {
		if (request_msg.find ("Content-Length: ") != std::string::npos) {
			content_length = std::strtol(request_msg.substr ((request_msg.find ("Content-Length: ") + 15),					\
											request_msg.find ("\r\n", request_msg.find ("Content-Length: ") + 15)).c_str(),	\
											NULL, 10);
			client.body_length = request_msg.size() - (header_end + 4);
			if (content_length != client.body_length)
			{
				client.get_timeout_instance().setSavedTime();
				return false;
			}
		}
		else if (request_msg.find("chunked") != std::string::npos) {
			if (request_msg.find ("0\r\n", header_end) == std::string::npos) {
				client.get_timeout_instance().setSavedTime();
				return false;
			}
			return true;
		}
	}
	return true;
}

void Server::recieveFailed(Client& client){
	for (unsigned long i = 0; i < read_timeout_list.size(); i++) {
		if (read_timeout_list[i] == &client) {
			read_timeout_list.erase(read_timeout_list.begin() + i);
			break;
		}
	}
}

void Server::recieveDone(Cycle& cycle, Client& client){
	client.do_parse(cycle);
	client.get_response_instance().set_body("");
	for (unsigned long i = 0; i < read_timeout_list.size(); i++) {
		if (read_timeout_list[i] == &client) {
			read_timeout_list.erase(read_timeout_list.begin() + i);
			break;
		}
	}
	if (client.get_status_code() < MOVED_PERMANENTLY && client.get_expect() == false) {
		try {
			if (client.get_cgi() == true) {
				client.set_property_for_cgi(client.get_request_instance());

				pid_t	cgi_pid = Cgi::execute_cgi(client.get_request_instance(),	\
													client.get_cgi_instance());
				if (cgi_pid != -1) {
					addEvent(cgi_pid, EVFILT_PROC, EV_ADD | EV_ONESHOT, NOTE_EXIT, 0, client.get_client_soket_ptr());
					client.set_cgi_fork_status (true);
					client.get_timeout_instance().setSavedTime();
					cgi_timeout_list.push_back(&client);
				}
				return ;
			}
			client.do_method_without_cgi(client.get_request_instance());
		} catch(int e) {
			client.set_status_code(e);
		}
	}
	prepSend(client);
}

void Server::prepSend(Client& client) {
	client.assemble_response();
	client.get_request_instance().get_request_msg() = "";
	addEvent(client.get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, event_type_client);
}

void Server::sendToClient(Client& client) {
	std::string response_msg = client.get_response_instance().get_response_message();
	int client_socket = client.get_client_soket();

	if (send(client_socket, response_msg.c_str(), response_msg.length() + 1, 0) == -1) {
		disconnectClient(client_socket);
		eventException(EVENT_FAIL_SEND, client_socket);
	}

	if (response_msg.find("Connection: close") != std::string::npos)
		disconnectClient(client_socket);
}

void Server::reclaimProcess(Client& client) {
	client.parse_cgi_response(client.get_cgi_instance());

	client.assemble_response();
	client.get_request_instance().get_request_msg() = "";
	addEvent(client.get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, &event_type_client);
}

void Server::disconnectClient(int client_socket) {
	if (close(client_socket) == 0)
		cur_connection--;
}

void Server::checkReadTimeout() {
	for (unsigned long i = 0; i < read_timeout_list.size(); i++) {
		if (read_timeout_list[i]->get_timeout_instance().checkDiffTimeout(READ_TIME_OUT) == true) {
			read_timeout_list[i]->set_status_code(REQUEST_TIMEOUT);
			read_timeout_list[i]->set_read_fail(true);
			read_timeout_list[i]->assemble_response();
			addEvent(read_timeout_list[i]->get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, getEventTypeClient());
			read_timeout_list.erase(read_timeout_list.begin() + i--);
		}
	}
}

void Server::checkCgiTimeout() {
	for (unsigned long i = 0; i < cgi_timeout_list.size(); i++) {
		if (cgi_timeout_list[i]->get_cgi() == false) {
			cgi_timeout_list.erase(cgi_timeout_list.begin() + i--);
			continue;
		}
		if (cgi_timeout_list[i]->get_cgi_fork_status() == true) {
			if (cgi_timeout_list[i]->get_timeout_instance().checkDiffTimeout(CGI_TIME_OUT) == true) {
				kill(cgi_timeout_list[i]->get_cgi_instance().get_pid(), SIGTERM);
				cgi_timeout_list.erase(cgi_timeout_list.begin() + i--);
				continue;
			}
		}
	}
}

char* getEventType(kevent_t* event) {
	return static_cast<char*>(event->udata);
}

void eventReadServer(Server& server, uintptr_t listen_socket) {
	server.acceptNewClient(listen_socket);
}

void eventReadClient(Cycle& cycle, Server& server, kevent_t* cur_event) {
	Client&	client = server.getClient(cur_event->ident);

	if (client.get_request_instance().get_request_msg() == "") {
		client.get_request_instance().set_cycle(cycle);
		client.init_client(cur_event->ident);
		server.getReadTimeoutList().push_back(&client);
	}

	int	res = server.recieveFromClient(client);
	if (res == -1)
		server.recieveFailed(client);
	else if (res == true)
		server.recieveDone(cycle, client);
}

void eventRead(Cycle& cycle, Server& server, kevent_t* cur_event) {
	char*	event_type = getEventType(cur_event);

	if (std::strcmp(event_type, "listen") == 0)
		eventReadServer(server, cur_event->ident);

	else if (std::strcmp(event_type, "client") == 0)
		eventReadClient(cycle, server, cur_event);
}

void eventWrite(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(cur_event->ident);
	server.sendToClient(client);
	client.reset_data();
}

uintptr_t getClientSocket(kevent_t* event) {
	return  *(static_cast<uintptr_t*>(event->udata));
}

void eventProc(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(getClientSocket(cur_event));
	server.reclaimProcess(client);
}

void startConnect(Cycle& cycle) {
    Server					server(cycle.getWorkerConnections() * 2, cycle.getWorkerConnections());
	uint32_t				new_events;
	kevent_t*				cur_event;

    server.prepConnect(cycle.getServerBlocks());

	while (1) {
		server.checkReadTimeout();
		server.checkCgiTimeout();

		new_events = server.pollingEvent();

		for (unsigned int i = 0; i < new_events; i++) {
			cur_event = &server.getEventOfList(i);

			if (server.checkErrorFlag(*cur_event) == true)
				continue;

			if (cur_event->filter == EVFILT_READ)
				eventRead(cycle, server, cur_event);
			else if (cur_event->filter == EVFILT_WRITE)
				eventWrite(server, cur_event);
			else if (cur_event->filter == EVFILT_PROC)
				eventProc(server, cur_event);
		}
	}
}
