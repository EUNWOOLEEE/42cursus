#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {
	public:
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();

		Bureaucrat& operator =(const Bureaucrat& obj);

		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

		class gradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high\n"; }
		};
		class gradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low\n"; }
		};

	private:
		Bureaucrat();
		
		const std::string	name;
		unsigned int		grade;
} ;

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif