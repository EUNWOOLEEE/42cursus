#include "../incs/Data.hpp"

Data::Data(std::string _name) : name(_name) {
	std::cout << "[OCCF] Data default constructor called\n";
}

Data::Data(const Data& obj) {
	std::cout << "[OCCF] Data copy constructor called\n";
	*this = obj;
}

Data::~Data(void) {
	std::cout << "[OCCF] Data destructor called\n";
}

Data& Data::operator =(const Data& obj) {
	std::cout << "[OCCF] Data copy assignment operator called\n";
	if (this != &obj)
		name = obj.name;
	return *this;
}
