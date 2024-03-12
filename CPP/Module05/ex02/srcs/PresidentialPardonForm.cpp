#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)	\
						: AForm(name, 25, 5) {
	std::cout << "[OCCF] PresidentialPardonForm defalut constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)	\
						: AForm(obj.getName(), 25, 5) {
	std::cout << "[OCCF] PresidentialPardonForm copy constructor called\n";

	setIsSigned(obj.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "[OCCF] PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& obj) {
	std::cout << "[OCCF] PresidentialPardonForm copy assignment operator called\n";

	if (this != &obj)
		setIsSigned(obj.getIsSigned());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (getExecuteGrade() >= executor.getGrade())
		std::cout << getName() << " is pardoned by " << executor.getName() << "\n";
	else
		throw gradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm& src) {
	out << src.getName() << ":\nsigned";
	if (src.getIsSigned() == true)
		out << "[ O ]\n";
	else
		out << "[ X ]\n";
	out << "grade for sign[ " << src.getSignGrade() << " ]\n";
	out << "grade for execute[ " << src.getExecuteGrade() << " ]\n";
	return out;
}
