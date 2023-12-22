#include "location.hpp"

Location::Location(void) {}

Location::Location(const Location& src) {
	*this = src;
}

Location& Location::operator =(const Location& src) {
	if (this != &src) {
	}
	return (*this);
}

Location::~Location(void) {}
