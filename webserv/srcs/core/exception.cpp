#include "exception.hpp"

Exception::Exception(const std::string& msg) : msg_(msg) {}

const char*	Exception::what() const {
	return msg_.c_str();
}
