#include "../incs/Mylist.hpp"

Mylist::Mylist(void) {
	// std::cout << "[OCCF] Mylist default constructor called\n";
}

Mylist::~Mylist(void) {
	// std::cout << "[OCCF] Mylist destructor called\n";
}

Mylist::Mylist(const Mylist& obj) : std::list<std::string>(obj) {
	// std::cout << "[OCCF] Mylist copy constructor called\n";
}

Mylist& Mylist::operator= (const Mylist& obj) {
	// std::cout << "[OCCF] Mylist copy assignment operator called\n";

	if (this != &obj) {
		clear();

		std::list<std::string>::const_iterator	it = obj.begin();
		std::list<std::string>::const_iterator	ite = obj.end();

		while (it != ite)
			push_back(*it++);
	}
	return *this;
}

std::string& Mylist::operator[] (unsigned int idx) {
	// std::cout << "[OCCF] array index operator called\n";

	if (idx >= this->size())
		throw std::out_of_range("out_of_range");
		
	std::list<std::string>::iterator	it = this->begin();
	std::advance(it, idx);

	return *it;
}

const std::string& Mylist::operator[] (unsigned int idx) const {
	// std::cout << "[OCCF] const array index operator called\n";
	
	if (idx >= this->size())
		throw std::out_of_range("out_of_range");
		
	std::list<std::string>::const_iterator	it = this->begin();
	std::advance(it, idx);

	return *it;
}