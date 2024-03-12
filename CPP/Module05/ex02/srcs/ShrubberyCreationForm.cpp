#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)	\
						: AForm(name, 145, 137) {
	std::cout << "[OCCF] ShrubberyCreationForm defalut constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)	\
						: AForm(obj.getName(), 145, 137) {
	std::cout << "[OCCF] ShrubberyCreationForm copy constructor called\n";

	setIsSigned(obj.getIsSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "[OCCF] ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& obj) {
	std::cout << "[OCCF] ShrubberyCreationForm copy assignment operator called\n";

	if (this != &obj)
		setIsSigned(obj.getIsSigned());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (getIsSigned() == false)
		throw formIsNotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw gradeTooLowException();
		
	std::ofstream file(getName() + "_shrubbery");
	file << shrub_trees;
}
