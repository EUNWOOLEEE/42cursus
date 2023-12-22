#ifndef CYCLE_HPP
# define CYCLE_HPP

# include <list>
# include <iostream>
# include "server.hpp"

class Cycle {
	public:
		Cycle(void);
		Cycle(const Cycle& obj);
		~Cycle(void);

		Cycle& operator =(const Cycle& src);

		void						setWorkerProcesses(u_int32_t n);
		void						setWorkerConnections(u_int32_t n);
		void						setClientMaxBodySize(u_int32_t n);

		int							getWorkerProcesses(void) const;
		int							getWorkerConnections(void) const;
		int							getClientMaxBodySize(void) const;
		std::list<Server>&			getServerList(void);
		const std::list<Server>&	getServerListConst(void) const;



	private:
		int					worker_processes;
		int					worker_connections;

		size_t				client_max_body_size;
		std::list<Server>	server_list;
		
};

#endif