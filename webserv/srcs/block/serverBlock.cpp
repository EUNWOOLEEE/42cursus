#include "../core/core.hpp"

ServerBlock::ServerBlock(void) : port(0) {}

ServerBlock::ServerBlock(const ServerBlock& src) { *this = src; }

ServerBlock::~ServerBlock(void) {}

ServerBlock& ServerBlock::operator =(const ServerBlock& src) {
	if (this != &src) {
		port = src.port;
		domain = src.domain;
		location_list = src.location_list;
	}
	return (*this);
}

void						ServerBlock::setPort(size_t _port) { port = _port; }
void						ServerBlock::setDomain(std::string _domain){ domain = _domain; }

size_t						ServerBlock::getPort(void) const { return port; }
const std::string&			ServerBlock::getDomain(void) const{ return domain; }
std::list<Location>&		ServerBlock::getLocationList(void) { return location_list; }
const std::list<Location>&	ServerBlock::getLocationListConst(void) const { return location_list; }
