#include "../core/core.hpp"

Server::Server(Event& _event, size_t _worker_connections) : event(_event),				\
															worker_connections(_worker_connections),	\
															cur_connection(0),							\
															event_type_listen("listen"),				\
															event_type_client("client"),				\
															event_type_cgi("cgi") {
}

Server::~Server(void) {
	for (unsigned int i = 0; i < listen_socket_list.size(); i++)
		close(listen_socket_list[i]);
}

std::vector<uintptr_t>&	Server::getListenSocketList(void) { return listen_socket_list; }
int						Server::getCurConnection(void) const { return cur_connection; }
Client&					Server::getClient(uintptr_t socket) { return clients[socket]; }
char*					Server::getEventTypeListen(void) { return event_type_listen; }
char*					Server::getEventTypeClient(void) { return event_type_client; }
char*					Server::getEventTypeCgi(void) { return event_type_cgi; }

void Server::prepConnect(std::vector<ServerBlock>& server_blocks) {
    sockaddr_in	server_addr;
    int			listen_socket;

	for (unsigned long i = 0; i < server_blocks.size(); i++) {
		for (unsigned long j = 0; j < i; j++)
            if (server_blocks[j].getPort() == server_blocks[i].getPort())
                continue;

        listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (listen_socket == -1)
            throw Exception(EVENT_FAIL_CREATE_SOCKET);
        listen_socket_list.push_back(listen_socket);

        std::memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(server_blocks[i].getPort());
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

		// setReuseAddress(listen_socket);

        if (bind(listen_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(sockaddr_in)) == -1)
            throw Exception(EVENT_FAIL_BIND);
        if (listen(listen_socket, LISTEN_QUEUE_SIZE) == -1)
            throw Exception(EVENT_FAIL_LISTEN);
        if (fcntl(listen_socket, F_SETFL, O_NONBLOCK) == -1)
            throw Exception(EVENT_FAIL_FCNTL);
        event.addEvent(listen_socket, EVFILT_READ, EV_ADD, 0, 0, &event_type_listen);
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
		event.addEvent(client_socket, EVFILT_READ, EV_ADD, 0, 0, &event_type_client);
		cur_connection++;
	}
	else {
		eventException(EVENT_CONNECT_FULL, 0);
	}
}

void Server::prepSend(Client& client) {
	client.assemble_response();
	client.get_request_instance().get_request_msg() = "";
	event.addEvent(client.get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, event_type_client);
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

	if (header_end == std::string::npos)
		return false;

	if (request_msg.find("POST") == 0 && request_msg.find ("100-continue") == std::string::npos) {
		if (request_msg.find ("Content-Length: ") != std::string::npos) {
			content_length = std::strtol(request_msg.substr ((request_msg.find ("Content-Length: ") + 15),					\
											request_msg.find ("\r\n", request_msg.find ("Content-Length: ") + 15)).c_str(),	\
											NULL, 10);
			client.body_length = request_msg.size() - (header_end + 4);
			if (content_length != client.body_length)
				return false;
		}
		else if (request_msg.find("chunked") != std::string::npos) {
			if (request_msg.find ("0\r\n", header_end) == std::string::npos)
				return false;
			return true;
		}
	}
	return true;
}

void Server::recieveFailed(Client& client) {
	event.addEvent(client.get_client_soket(), EVFILT_TIMER, EV_DELETE, 0, 0, getEventTypeClient());
	prepDisconnect(client);
}

void Server::recieveDone(Cycle& cycle, Client& client){
	client.do_parse(cycle);
	client.get_response_instance().set_body("");

	event.addEvent(client.get_client_soket(), EVFILT_TIMER, EV_DELETE, 0, 0, getEventTypeClient());

	if (client.get_status_code() < MOVED_PERMANENTLY && client.get_expect() == false) {
		try {
			if (client.get_cgi() == true) {
				client.set_property_for_cgi(client.get_request_instance());

				pid_t	cgi_pid = Cgi::execute_cgi(client.get_request_instance(),	\
													client.get_cgi_instance());
				if (cgi_pid != -1) {
					event.addEvent(cgi_pid, EVFILT_PROC, EV_ADD | EV_ONESHOT, NOTE_EXIT, 0, client.get_client_soket_ptr());
					event.addEvent(client.get_client_soket(), EVFILT_TIMER, EV_ADD | EV_ONESHOT, NOTE_SECONDS, CGI_TIME_OUT, getEventTypeCgi());
					client.set_cgi_fork_status (true);
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

void Server::reclaimProcess(Client& client) {
	client.parse_cgi_response(client.get_cgi_instance());
	client.assemble_response();
	client.get_request_instance().get_request_msg() = "";
	event.addEvent(client.get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, &event_type_client);
}

void Server::prepDisconnect(Client& client) {
	client.set_status_code(REQUEST_TIMEOUT);
	client.set_read_fail(true);
	client.assemble_response();
	event.addEvent(client.get_client_soket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, getEventTypeClient());
}

void Server::disconnectClient(int client_socket) {
	if (close(client_socket) == 0)
		cur_connection--;
}

bool Server::checkErrorFlag(kevent_t& kevent) {
	if ((kevent.flags & EV_EOF && kevent.filter != EVFILT_PROC)	|| kevent.flags & EV_ERROR) {
		disconnectClient(kevent.ident);
		return true;
	}
	return false;
}

void startConnect(Cycle& cycle) {
	Event	event(cycle.getWorkerConnections() * 2);
    Server	server(event, cycle.getWorkerConnections());

    server.prepConnect(cycle.getServerBlocks());

	while (1) {
		uint32_t new_events = event.pollingEvent();

		for (unsigned int i = 0; i < new_events; i++) {
			kevent_t* cur_event = &event.getEventOfList(i);

			if (server.checkErrorFlag(*cur_event) == true)
				continue;

			if (cur_event->filter == EVFILT_READ)
				event.eventRead(cycle, server, cur_event);
			else if (cur_event->filter == EVFILT_WRITE)
				event.eventWrite(server, cur_event);
			else if (cur_event->filter == EVFILT_PROC)
				event.eventProc(server, cur_event);
			else if (cur_event->filter == EVFILT_TIMER)
				event.eventTimer(server, cur_event);
		}
	}
}

void setReuseAddress(int listen_socket) {
	int	optval = 1;
	setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
}
