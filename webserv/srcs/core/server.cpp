#include "server.hpp"

Server::Server(void) \
		: port(0), domain(), error_page(), location_list() {}

Server::Server(const Server& src) {
	*this = src;
}

Server& Server::operator =(const Server& src) {
	if (this != &src) {
	}
	return (*this);
}

Server::~Server(void) {}

void Server::setPort(uint32_t _port){
	port = _port;
}

void Server::setDomain(std::string _domain){
	domain = _domain;
}

void Server::setErrorPage(std::string _error_page){
	error_page = _error_page;
}

uint32_t Server::getPort(void) const{
	return port;
}

const std::string& Server::getDomain(void) const{
	return domain;
}

const std::string& Server::getErrorPage(void) const{
	return error_page;
}

