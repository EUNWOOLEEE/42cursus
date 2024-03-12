#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)	\
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
	if (getExecuteGrade() >= executor.getGrade()) {
		std::ofstream file(getName() + "_shrubbery");
		file << shrub_trees;
	}
	else
		throw gradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm& src) {
	out << src.getName() << ":\nsigned";
	if (src.getIsSigned() == true)
		out << "[ O ]\n";
	else
		out << "[ X ]\n";
	out << "grade for sign[ " << src.getSignGrade() << " ]\n";
	out << "grade for execute[ " << src.getExecuteGrade() << " ]\n";
	return out;
}
