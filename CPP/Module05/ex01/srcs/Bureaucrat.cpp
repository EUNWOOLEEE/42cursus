#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade)	\
			: name(_name), grade(_grade) {
	std::cout << "[OCCF] Bureaucrat defalut constructor called\n";
	if (_grade < 1)
		throw gradeTooHighException();
	if (150 < _grade)
		throw gradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)	\
			: name(obj.name), grade(obj.grade) {
	std::cout << "[OCCF] Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "[OCCF] Bureaucrat destructor called\n";
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& obj) {
	std::cout << "[OCCF] Bureaucrat copy assignment operator called\n";
	if (this != &obj)
		grade = obj.grade;
	return *this;
}

const std::string&	Bureaucrat::getName(void) const { return name; }
unsigned int		Bureaucrat::getGrade(void) const { return grade; }

void Bureaucrat::incGrade(void) {
	if (grade == 1)
		throw gradeTooHighException();
	grade--;
}

void Bureaucrat::decGrade(void) {
	if (grade == 150)
		throw gradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	} catch (Form::gradeTooLowException& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what();
		return ;
	}
	std::cout << name << " signed " << form.getName() << "\n";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& src) {
	return out << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n";
}
