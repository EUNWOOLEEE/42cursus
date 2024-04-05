#include "../incs/Data.hpp"

Data::Data(std::string _str, int _n) : str(_str), n(_n) {
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
	if (this != &obj) {
		str = obj.str;
		n = obj.n;
	}
	return *this;
}

std::string& Data::getStr(void) { return str; }
int Data::getN(void) { return n; }