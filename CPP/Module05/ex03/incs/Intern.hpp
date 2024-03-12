#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define fp std::pair<std::string, AForm* (*)(const std::string&)>

class Intern {
	public:
		Intern(void);
		~Intern(void);

		AForm* makeForm(const std::string name, const std::string target);

		static fp form_type[3];

	private:
		Intern(Intern& obj);
		Intern& operator =(const Intern& obj);
};

#endif