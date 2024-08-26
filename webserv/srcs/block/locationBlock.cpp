#include "../core/core.hpp"

LocationBlock::LocationBlock(std::string _location_path)	\
	: location_path(_location_path), allowed_method(0), autoindex(-1) {}

LocationBlock::LocationBlock(const LocationBlock& src) { *this = src; }

LocationBlock::~LocationBlock(void) {}

LocationBlock& LocationBlock::operator =(const LocationBlock& src) {
	if (this != &src) {
		location_path = src.location_path;
		sub_root = src.sub_root;
		allowed_method = src.allowed_method;
		autoindex = src.autoindex;
		index = src.index;
	}
	return (*this);
}

void						LocationBlock::setSubRoot(std::string _sub_root) { sub_root = _sub_root; }
void						LocationBlock::setAllowedMethod(int _allowed_method) { allowed_method = _allowed_method; }
void						LocationBlock::setAutoIndex(int _autoindex) { autoindex = _autoindex; }

const std::string&			LocationBlock::getLocationPath(void) const { return location_path; }
const std::string&			LocationBlock::getSubRoot(void) const { return sub_root; }
int							LocationBlock::getAllowedMethod(void) const { return allowed_method; }
int							LocationBlock::getAutoIndex(void) const { return autoindex; }
std::vector<std::string>&	LocationBlock::getIndex(void) { return index; }

