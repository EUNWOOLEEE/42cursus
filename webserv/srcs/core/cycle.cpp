#include "cycle.hpp"

Cycle::Cycle(void) \
	: worker_processes(0), worker_connections(0), client_max_body_size(0) {}

Cycle::Cycle(const Cycle& src) {
	*this = src;
}

Cycle& Cycle::operator =(const Cycle& src) {
	if (this != &src) {
	}
	return (*this);
}

Cycle::~Cycle(void) {}

void	Cycle::setWorkerProcesses(u_int32_t n) {
	worker_processes = n;
}

int		Cycle::getWorkerProcesses(void) const {
	return worker_processes;
}

void	Cycle::setWorkerConnections(u_int32_t n) {
	worker_connections = n;
}

int		Cycle::getWorkerConnections(void) const {
	return worker_connections;
}

void	Cycle::setClientMaxBodySize(u_int32_t n) {
	client_max_body_size = n;
}

int		Cycle::getClientMaxBodySize(void) const {
	return client_max_body_size;
}

std::list<Server>& Cycle::getServerList(void){
	return server_list;
}

const std::list<Server>& Cycle::getServerListConst(void) const{
	return server_list;
}
