#include "../incs/AForm.hpp"

AForm::AForm(std::string _name, int _sign_grade, int _execute_grade)	 \
		: name(_name), sign_grade(_sign_grade), execute_grade(_execute_grade) {
	std::cout << "[OCCF] AForm defalut constructor called\n";

	if (sign_grade < 1 || execute_grade < 1)
		throw gradeTooHighException();
	if (150 < sign_grade || 150 < execute_grade)
		throw gradeTooLowException();

	is_signed = false;
}

AForm::AForm(const AForm& obj)							\
		: name(obj.name), is_signed(obj.is_signed),		\
		sign_grade(obj.sign_grade), execute_grade(obj.execute_grade) {
	std::cout << "[OCCF] AForm copy constructor called\n";
}

AForm::~AForm() {
	std::cout << "[OCCF] AForm destructor called\n";
}

AForm& AForm::operator =(const AForm& obj) {
	std::cout << "[OCCF] AForm copy assignment operator called\n";
	if (this != &obj)
		is_signed = obj.is_signed;
	return *this;
}

const std::string&	AForm::getName(void) const { return name; }
bool				AForm::getIsSigned(void) const { return is_signed; }
unsigned int		AForm::getSignGrade(void) const { return sign_grade; }
unsigned int		AForm::getExecuteGrade(void) const { return execute_grade; }

void				AForm::setIsSigned(bool _is_signed) { is_signed = _is_signed; }

void AForm::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw gradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm& src) {
	out << src.getName() << ":\nsigned";
	if (src.getIsSigned() == true)
		out << "[ O ]\n";
	else
		out << "[ X ]\n";
	out << "grade for sign[ " << src.getSignGrade() << " ]\n";
	out << "grade for execute[ " << src.getExecuteGrade() << " ]\n";
	return out;
}
