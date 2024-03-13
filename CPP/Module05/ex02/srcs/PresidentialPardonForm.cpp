#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)	\
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
	if (getIsSigned() == false)
		throw formIsNotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw gradeTooLowException();
		
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
}
