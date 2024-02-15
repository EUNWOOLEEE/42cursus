#include "../incs/bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& obj) {}

std::string&	Bureaucrat::getName(void);
unsigned int	Bureaucrat::getGrade(void);