#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string _name, int _sign_grade, int _excute_grade);
		AForm(const AForm& obj);
		virtual ~AForm(void);

		AForm& operator =(const AForm& obj);

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecuteGrade(void) const;

		void				setIsSigned(bool _is_signed);

		void 				beSigned(Bureaucrat const& bureaucrat);
		virtual void 		execute(Bureaucrat const& executor) const = 0;

		class gradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high\n"; }
		};
		class gradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low\n"; }
		};
		class formIsNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form is not signed\n"; }
		};

	private:
		AForm(void);

		const std::string		name;
		bool					is_signed;
		const unsigned int		sign_grade;
		const unsigned int		execute_grade;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif