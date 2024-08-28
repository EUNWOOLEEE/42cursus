#include "../core/core.hpp"

Event::Event(int event_list_size) {
	event_queue = kqueue();
	if (event_queue == -1)
		throw Exception(EVENT_FAIL_CREATE_KQ);
	event_list.resize(event_list_size);
	kevent_timeout.tv_sec = 5;
	kevent_timeout.tv_nsec = 0;
}

Event::~Event(void) {
	close(event_queue);
}

int			Event::getEventQueue(void) const { return event_queue; }
kevent_t&	Event::getEventOfList(int idx) { return event_list[idx]; }
char*		Event::getEventType(kevent_t* event) const { return static_cast<char*>(event->udata); }
uintptr_t	Event::getClientSocket(kevent_t* event) const { return  *(static_cast<uintptr_t*>(event->udata)); }

void Event::addEvent(uintptr_t ident, int16_t filter, uint16_t flags,	\
						size_t fflags, intptr_t data, void* udata) {
	kevent_t	temp;

	EV_SET(&temp, ident, filter, flags, fflags, data, udata);
	kevent(event_queue, &temp, 1, NULL, 0, NULL);
}

size_t Event::pollingEvent() {
	int	new_events = kevent(event_queue, NULL, 0, &event_list[0], event_list.size(), &kevent_timeout);

	if (new_events == -1)
		throw Exception(EVENT_FAIL_KEVENT);
	return new_events;
}

void Event::eventRead(Cycle& cycle, Server& server, kevent_t* cur_event) {
	char*	event_type = getEventType(cur_event);

	if (std::strcmp(event_type, "listen") == 0)
		eventReadServer(server, cur_event->ident);
	else if (std::strcmp(event_type, "client") == 0)
		eventReadClient(cycle, server, cur_event);
}

void Event::eventReadServer(Server& server, uintptr_t listen_socket) {
	server.acceptNewClient(listen_socket);
}

void Event::eventReadClient(Cycle& cycle, Server& server, kevent_t* cur_event) {
	Client&	client = server.getClient(cur_event->ident);

	if (client.get_request_instance().get_request_msg() == "") {
		client.get_request_instance().set_cycle(cycle);
		client.init_client(cur_event->ident);
	}

	int	res = server.recieveFromClient(client);
	if (res == -1)
		server.recieveFailed(client);
	else if (res == true)
		server.recieveDone(cycle, client);
	else if (res == false)
		addEvent(cur_event->ident, EVFILT_TIMER, EV_ADD | EV_ONESHOT, NOTE_SECONDS, READ_TIME_OUT, server.getEventTypeClient());
}

void Event::eventWrite(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(cur_event->ident);
	server.sendToClient(client);
	client.reset_data();
}

void Event::eventProc(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(getClientSocket(cur_event));
	server.reclaimProcess(client);
	addEvent(client.get_cgi_instance().get_pid(), EVFILT_TIMER, EV_DELETE, 0, 0, server.getEventTypeCgi());
}

void Event::eventTimer(Server& server, kevent_t* cur_event) {
	char*	event_type = getEventType(cur_event);

	if (std::strcmp(event_type, "client") == 0)
		eventTimerClient(server, cur_event);
	else if (std::strcmp(event_type, "cgi") == 0)
		eventTimerCgi(server, cur_event);
}

void Event::eventTimerClient(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(getClientSocket(cur_event));

	server.prepDisconnect(client);
}

void Event::eventTimerCgi(Server& server, kevent_t* cur_event) {
	Client& client = server.getClient(cur_event->ident);

	addEvent(client.get_cgi_instance().get_pid(), EVFILT_PROC, EV_DELETE, 0, 0, client.get_client_soket_ptr());
	kill(client.get_cgi_instance().get_pid(), SIGTERM);
}