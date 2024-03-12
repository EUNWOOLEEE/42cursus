#include "../incs/Bureaucrat.hpp"
#include "../incs/Intern.hpp"

int main() {
	try {
		Intern intern;
		Bureaucrat a("a", 1);

		std::cout << "----- Test: Shrubbery------\n\n";
		AForm* shrub = intern.makeForm("shrubbery creation", "shrub");
		// std::cout << shrub << " " << *shrub << "\n";


		// std::cout << "----- Test: Robotomy------\n\n";
		// Bureaucrat a("a", 45);
		// std::cout << a << "\n";

		// RobotomyRequestForm robo("robo");
		// std::cout << robo << "\n";
		// a.signForm(robo);
		// a.executeForm(robo);
		// std::cout << robo << "\n";


		// std::cout << "----- Test: Pardon------\n\n";
		// Bureaucrat a("a", 5);
		// std::cout << a << "\n";

		// PresidentialPardonForm president("president");
		// std::cout << president << "\n";
		// a.signForm(president);
		// a.executeForm(president);
		// std::cout << president << "\n";


		// std::cout << "----- Test: Try execute before sign and low grade------\n\n";
		// Bureaucrat a("a", 10);
		// std::cout << a << "\n";
		// PresidentialPardonForm president("president");
		// std::cout << president << "\n";
		// a.executeForm(president);
		// a.signForm(president);
		// std::cout << president << "\n";
		// a.executeForm(president);


		// std::cout << "------------ Test: copy ------------\n";
		// ShrubberyCreationForm shrub1("shrub1");
		// ShrubberyCreationForm shrub2("shrub2");
		// ShrubberyCreationForm shrub3(shrub1);
		// ShrubberyCreationForm shrub4("shrub4");
		// shrub4 = shrub2;
		// std::cout << shrub3 << "\n" << shrub4 << "\n";

	} catch (const Bureaucrat::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const Bureaucrat::gradeTooLowException& e) {
		std::cout << e.what();
	} catch (const AForm::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const AForm::gradeTooLowException& e) {
		std::cout << e.what();
	}

	return 0;
}