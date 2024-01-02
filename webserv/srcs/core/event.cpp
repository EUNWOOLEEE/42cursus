#include "core.hpp"

static void startConnect(Cycle &cycle, Worker &worker);
static void addEvent(std::vector<struct kevent> &change_list, uintptr_t ident, int16_t filter, \
					uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
static void acceptNewClient(int listen_socket, std::map<int, std::string> &clients,
							std::vector<struct kevent> &change_list);
static void recieveFromClient(int client_socket, std::map<int, std::string> &clients);

void prepConnect(Cycle &cycle, int id) {
	Worker		worker(id);
	sockaddr_in	server_addr;
	// socklen_t	server_addr_size;
	int			listen_socket = worker.getListenSocket();

	std::memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(listen_socket, reinterpret_cast<sockaddr *>(&server_addr), \
				sizeof(sockaddr_in)) == -1)
		setException(EVENT_BIND_FAIL);
	if (listen(listen_socket, LISTEN_QUEUE_SIZE) == -1)
		setException(EVENT_LISTEN_FAIL);
	fcntl(listen_socket, F_SETFL, O_NONBLOCK);
	startConnect(cycle, worker);
}

static void startConnect(Cycle &cycle, Worker &worker) {
	uintptr_t					listen_socket = worker.getListenSocket();
	std::map<int, std::string>	clients;
	std::vector<struct kevent>	change_list, event_list(EVENT_LIST_INIT_SIZE);

	uint32_t					new_events;
	struct kevent				*cur_event;

	addEvent(change_list, listen_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	
	while (1) {
		//timeout 설정해야 할 듯
		new_events = kevent(worker.getEventQueue(), &change_list[0], change_list.size(), \
							&event_list[0], event_list.size(), NULL);
		if (new_events > event_list.size()) {
			event_list.resize(new_events);
			kevent(worker.getEventQueue(), &change_list[0], change_list.size(), \
					&event_list[0], event_list.size(), NULL);
		}
		change_list.clear();

		for (uint32_t i = 0; i < new_events; i++) {
			cur_event = &event_list[i];

			if (cur_event->flags == EV_ERROR) {
				//error
			}
			if (cur_event->filter == EVFILT_READ) {
				if (cur_event->ident == listen_socket) {
					acceptNewClient(listen_socket, clients, change_list);
				}
				else if (clients.find(cur_event->ident) != clients.end()) {
					recieveFromClient(cur_event->ident, clients);
					// request parsing
					(void)cycle;
					// map에서 해당 [socket] data clear?
				}
			}
			else if (cur_event->filter == EVFILT_WRITE) {
				// response send
				std::string	response;
				if (send(cur_event->ident, response.c_str(), response.length(), 0) == -1)
					setException(EVENT_SEND_FAIL);
			}
		}
	}
}

static void addEvent(std::vector<struct kevent> &change_list, uintptr_t ident, int16_t filter, \
					uint16_t flags, uint32_t fflags, intptr_t data, void *udata) {
	struct kevent	temp;

	EV_SET(&temp, ident, filter, flags, fflags, data, udata);
	change_list.push_back(temp);
}

static void acceptNewClient(int listen_socket, std::map<int, std::string> &clients,
							std::vector<struct kevent> &change_list) {
	uintptr_t	client_socket;

	if ((client_socket = accept(listen_socket, NULL, NULL)) == -1)
		setException(EVENT_ACCEPT_FAIL);
	
	fcntl(client_socket, F_SETFL, O_NONBLOCK);
	
	addEvent(change_list, client_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	addEvent(change_list, client_socket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	clients[client_socket] = "";
}

static void recieveFromClient(int client_socket, std::map<int, std::string> &clients) {
	char	buf[BUF_SIZE] = {0,};
	int		recieve_size;

	while ((recieve_size = recv(client_socket, buf, BUF_SIZE - 1, 0)) != -1) {
		buf[recieve_size] = '\0';
		std::string	tmp(buf, recieve_size);
		clients[client_socket] += tmp;
	}
	if (recieve_size == -1 || errno != EAGAIN)
		setException(EVENT_RECV_FAIL);
}