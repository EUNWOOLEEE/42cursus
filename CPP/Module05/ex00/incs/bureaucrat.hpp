#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();

		Bureaucrat& operator =(const Bureaucrat& obj);

		std::string&	getName(void);
		unsigned int	getGrade(void);

	private:
		const std::string	name;
		unsigned int		grade;
} ;

#endif