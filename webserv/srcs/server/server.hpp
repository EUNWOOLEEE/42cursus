#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include <cstring>
# include <fcntl.h>
# include <signal.h>
# include <iostream>
# include <netinet/ip.h>

# include "../server/event.hpp"
# include "../client/Client.hpp"

# define LISTEN_QUEUE_SIZE 30
# define READ_TIME_OUT 30
# define CGI_TIME_OUT 30

class Event;

class Server {
	public:
		Server(Event& _event, size_t _worker_connections);
		~Server(void);

		std::vector<uintptr_t>&	getListenSocketList(void);
		int						getCurConnection(void) const;
		Client&					getClient(uintptr_t socket);

		void					prepConnect(std::vector<ServerBlock>& server_blocks);
		void					acceptNewClient(int client_socket);
		void					prepSend(Client& client);
		void					sendToClient(Client& client);
		int						recieveFromClient(Client& client);
		void					recieveFailed( Client& client);
		void					recieveDone(Cycle& cycle, Client& client);
		void					reclaimProcess(Client& client);
		void 					prepDisconnect( Client& client);
		void					disconnectClient(int client_socket);
		bool					checkErrorFlag(kevent_t& kevent);

	private:
		Server(const Server& src);
		Server& operator =(const Server& src);

		Event&						event;

		std::vector<uintptr_t>		listen_socket_list;
		const size_t				worker_connections;
		size_t						cur_connection;
		
	    std::map<uintptr_t, Client>	clients;
};

void	startConnect(Cycle& cycle);
bool	checkOverlapedPort(std::vector<ServerBlock>& server_blocks, size_t port, int range);
int		getNewListenSocket(std::vector<uintptr_t>& listen_socket_list);
void	initServerAddr(sockaddr_in& server_addr, size_t port);
void	setReuseAddress(int listen_socket);
void	setNewListenSocket(sockaddr_in& server_addr, int listen_socket);
int		getNewClientSocket(int listen_socket);
bool	setNewClientSocket(size_t client_socket);

#endif
