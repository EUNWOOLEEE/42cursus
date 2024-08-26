#ifndef CYCLE_HPP
# define CYCLE_HPP

# include "../block/serverBlock.hpp"

# include <vector>
# include <iostream>

# define WORKER_PROCESS_MAX 2
# define WORKER_CONNECTION_MAX 1024

class Cycle {
	public:
		Cycle(const char** _envp);
		Cycle(const Cycle& obj);
		~Cycle(void);

		Cycle& operator =(const Cycle& src);

		void						setWorkerConnections(u_int32_t n);
		void						setClientMaxBodySize(size_t n);
		void						setUriLimitLength(size_t n);
		void						setMainRoot(std::string _path);
		void						setDefaultErrorRoot(std::string _path);

		const char**				getEnvp(void) const;
		int							getWorkerConnections(void) const;
		int							getClientMaxBodySize(void) const;
		int							getUriLimitLength(void) const;
		const std::string&			getMainRoot(void) const;
		const std::string&			getDefaultErrorRoot(void) const;
		std::vector<ServerBlock>&	getServerBlocks(void);

	private:
		Cycle(void);

		const char**		envp;

		size_t				worker_connections;
		size_t				client_max_body_size;
		size_t				uri_limit_length;
		std::string			main_root;
		std::string			default_error_root;

		std::vector<ServerBlock>	server_blocks;
};

#endif