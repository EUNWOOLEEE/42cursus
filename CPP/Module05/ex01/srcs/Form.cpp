#include "../incs/Form.hpp"

Form::Form(std::string _name, int _sign_grade, int _execute_grade)	 \
		: name(_name), sign_grade(_sign_grade), execute_grade(_execute_grade) {
	std::cout << "[OCCF] Form defalut constructor called\n";

	if (sign_grade < 1 || execute_grade < 1)
		throw gradeTooHighException();
	if (150 < sign_grade || 150 < execute_grade)
		throw gradeTooLowException();

	is_signed = false;
}

Form::Form(const Form& obj)								\
		: name(obj.name), is_signed(obj.is_signed),		\
		sign_grade(obj.sign_grade), execute_grade(obj.execute_grade) {
	std::cout << "[OCCF] Form copy constructor called\n";
}

Form::~Form(void) {
	std::cout << "[OCCF] Form destructor called\n";
}

Form& Form::operator =(const Form& obj) {
	std::cout << "[OCCF] Form copy assignment operator called\n";
	
	if (this != &obj)
		is_signed = obj.is_signed;
	return *this;
}

const std::string&	Form::getName(void) const { return name; }
bool				Form::getIsSigned(void) const { return is_signed; }
unsigned int		Form::getSignGrade(void) const { return sign_grade; }
unsigned int		Form::getExecuteGrade(void) const { return execute_grade; }

void Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw gradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const Form& src) {
	out << src.getName() << ":\nsigned";
	if (src.getIsSigned() == true)
		out << "[ O ]\n";
	else
		out << "[ X ]\n";
	out << "grade for sign[ " << src.getSignGrade() << " ]\n";
	out << "grade for execute[ " << src.getExecuteGrade() << " ]\n";
	return out;
}
