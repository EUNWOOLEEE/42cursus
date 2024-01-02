#include "location.hpp"

Location::Location(std::string _block_path) : block_path(_block_path) {}

Location::Location(const Location& src) {
	*this = src;
}

Location::~Location(void) {}

Location& Location::operator =(const Location& src) {
	if (this != &src) {
		block_path = src.block_path;
		static_path = src.static_path;
	}
	return (*this);
}

void Location::setStaticPath(std::string _static_path) {
	static_path = _static_path;
}

const std::string& Location::getBlockPath(void) const {
	return block_path;
}

const std::string& Location::getStaticPath(void) const {
	return static_path;
}
