#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)	\
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
	
	if (getExecuteGrade() >= executor.getGrade()) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		int	random = std::rand() % 2;
		if (random)
			std::cout << "(whirring...) " << getName() << " is robotomized with 50% probability\n";
		else
			std::cout << "Fail to robotomize\n";
	}
	else
		throw gradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm& src) {
	out << src.getName() << ":\nsigned";
	if (src.getIsSigned() == true)
		out << "[ O ]\n";
	else
		out << "[ X ]\n";
	out << "grade for sign[ " << src.getSignGrade() << " ]\n";
	out << "grade for execute[ " << src.getExecuteGrade() << " ]\n";
	return out;
}
