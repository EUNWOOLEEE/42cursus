#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)	\
						: AForm(name, 72, 45) {
	std::cout << "[OCCF] RobotomyRequestForm defalut constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)	\
						: AForm(obj.getName(), 72, 45) {
	std::cout << "[OCCF] RobotomyRequestForm copy constructor called\n";

	setIsSigned(obj.getIsSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "[OCCF] RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& obj) {
	std::cout << "[OCCF] RobotomyRequestForm copy assignment operator called\n";

	if (this != &obj)
		setIsSigned(obj.getIsSigned());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (getIsSigned() == false)
		throw formIsNotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw gradeTooLowException();

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int	random = std::rand() % 2;
	if (random)
		std::cout << "(whirring...) " << getName() << " is robotomized with 50% probability\n";
	else
		std::cout << "Fail to robotomize\n";
}
