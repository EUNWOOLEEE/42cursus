#ifndef EVENT_HPP
# define EVENT_HPP

# include <iostream>
# include <vector>
# include <sys/event.h>

# include "../core/cycle.hpp"
# include "../server/server.hpp"

typedef struct kevent kevent_t;

class Server;

class Event {
	public:
		Event(int event_list_size);
		~Event(void);

		int						getEventQueue(void) const;
		kevent_t&				getEventOfList(int idx);
		char*					getEventTypeListen(void);
		char*					getEventTypeClient(void);
		char*					getEventTypeCgi(void);
		char*					getEventType(kevent_t* event) const;
		uintptr_t				getClientSocket(kevent_t* event) const;

		void					addEvent(uintptr_t ident, int16_t filter,	\
										uint16_t flags,	size_t fflags,		\
										intptr_t data, void* udata);
		size_t					pollingEvent();
		void					eventRead(Cycle& cycle, Server& server, kevent_t* cur_event);
		void 					eventReadServer(Server& server, uintptr_t listen_socket);
		void 					eventReadClient(Cycle& cycle, Server& server, kevent_t* cur_event);
		void					eventWrite(Server& server, kevent_t* cur_event);
		void					eventProc(Server& server, kevent_t* cur_event);
		void					eventTimer(Server& server, kevent_t* cur_event);
		void					eventTimerClient(Server& server, kevent_t* cur_event);
		void					eventTimerCgi(Server& server, kevent_t* cur_event);

	private:
		Event(const Event& src);
		Event& operator =(const Event& src);

		int						event_queue;
	    std::vector<kevent_t>	event_list;

		struct timespec			kevent_timeout;

		char					event_type_listen[8];
		char					event_type_client[7];
		char					event_type_cgi[4];
};


#endif
