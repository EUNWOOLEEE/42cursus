#include "../incs/Bureaucrat.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"

int main() {
	try {
		std::cout << "----- Test: Shrubbery------\n\n";
		Bureaucrat a("a", 137);
		std::cout << a << "\n";

		ShrubberyCreationForm shrub("shrub");
		std::cout << shrub << "\n";
		a.signForm(shrub);
		a.executeForm(shrub);
		std::cout << shrub << "\n";


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


		// std::cout << "------------ Test: copy ------------\n";
		// AForm e(c);
		// AForm f("f", 1, 1);
		// f = d;
		// std::cout << e << "\n" << f << "\n";

		// std::cout << "----- Test: invalid argument ------\n\n";
		// AForm e("e", 0, 1);
		// AForm f("f", 150, 151);


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