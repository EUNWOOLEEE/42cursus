#include "../incs/Intern.hpp"

fp Intern::form_type[] = { std::make_pair("shrubbery creation", &ShrubberyCreationForm::makeInstance),	\
							std::make_pair("robotomy requset", &RobotomyRequestForm::makeInstance),		\
							std::make_pair("presidential pardon", &PresidentialPardonForm::makeInstance)};

Intern::Intern(void) {
	std::cout << "[OCCF] Intern defalut constructor called\n";
}

Intern::~Intern(void) {
	std::cout << "[OCCF] Intern destructor called\n";
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	for (int i = 0; i < 3; i++) {
		if (name == form_type[i].first) {
			AForm* tmp_form = form_type[i].second(target);
			std::cout << "Intern creates " << target << "\n";
			return tmp_form;
		}
	}

	std::cout << "Form \"" << name << "\" is no exist\n";
	std::cout << "You can use the names below\n";
	for (int i = 0; i < 3; i++)
		std::cout << form_type[i].first << "\n";
	return NULL;
}
