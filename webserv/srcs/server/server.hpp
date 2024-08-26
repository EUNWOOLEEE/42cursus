#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include <vector>
# include <cstring>
# include <fcntl.h>
# include <signal.h>
# include <iostream>
# include <sys/event.h>
# include <netinet/ip.h>

# include "../client/Client.hpp"

# define LISTEN_QUEUE_SIZE 30
# define READ_TIME_OUT 30
# define CGI_TIME_OUT 30

typedef struct kevent kevent_t;

class Server {
	public:
		Server(int event_list_size, size_t _worker_connections);
		~Server(void);

		int						getEventQueue(void) const;
		std::vector<uintptr_t>&	getListenSocketList(void);
		int						getCurConnection(void) const;
		Client&					getClient(uintptr_t socket);
		std::vector<Client*>&	getReadTimeoutList(void);
		std::vector<Client*>&	getCGITimeoutList(void);
		kevent_t&				getEventOfList(int idx);
		char*					getEventTypeListen(void);
		char*					getEventTypeClient(void);
		char*					getEventTypeCgi(void);

		void					addEvent(uintptr_t ident, int16_t filter,	\
										uint16_t flags,	size_t fflags,		\
										intptr_t data, void* udata);
		size_t					pollingEvent();
		bool					checkErrorFlag(kevent_t& kevent);

		void					prepConnect(std::vector<ServerBlock>& server_blocks);
		void					acceptNewClient(int client_socket);
		void					sendToClient(Client& client);
		int						recieveFromClient(Client& client);
		void					recieveFailed(Client& client);
		void					recieveDone(Cycle& cycle, Client& client);
		void					prepSend(Client& client);
		void					reclaimProcess(Client& client);
		void					disconnectClient(int client_socket);

		void					checkReadTimeout(void);
		void					checkCgiTimeout(void);

	private:
		Server(const Server& src);
		Server& operator =(const Server& src);

		int						event_queue;
		std::vector<uintptr_t>	listen_socket_list;
		const size_t			worker_connections;
		size_t					cur_connection;

	    std::vector<kevent_t>	event_list;
		struct timespec			kevent_timeout;
		
	    std::map<uintptr_t, Client>	clients;
		std::vector<Client*>	read_timeout_list;
		std::vector<Client*>	cgi_timeout_list;

		char					event_type_listen[8];
		char					event_type_client[7];
		char					event_type_cgi[4];
};

void startConnect(Cycle& cycle);

#endif
