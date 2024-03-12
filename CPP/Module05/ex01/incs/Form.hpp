#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string _name, int _sign_grade, int _excute_grade);
		Form(const Form& obj);
		~Form(void);

		Form& operator =(const Form& obj);

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecuteGrade(void) const;

		void 				beSigned(Bureaucrat const& bureaucrat);

		class gradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high\n"; }
		};
		class gradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low\n"; }
		};

	private:
		Form(void);
		
		const std::string		name;
		bool					is_signed;
		const unsigned int		sign_grade;
		const unsigned int		execute_grade;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif