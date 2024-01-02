#ifndef WORKER_HPP
# define WORKER_HPP

# include <unistd.h>
# include <sys/event.h>
# include <netinet/ip.h>

class Worker {
	public:
		Worker(int id);
		Worker(const Worker& obj);
		~Worker(void);

		Worker& operator =(const Worker& src);

		int	getWorkerId(void) const;
		int	getEventQueue(void) const;
		int	getListenSocket(void) const;

	private:
		Worker(void);

		int	worker_id;
		int	event_queue;
		int	listen_socket;
};

void createWorker(Cycle &cycle);

# include "event.hpp"

#endif