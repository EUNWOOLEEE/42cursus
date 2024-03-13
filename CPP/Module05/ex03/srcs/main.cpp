#include "../incs/Bureaucrat.hpp"
#include "../incs/Intern.hpp"

void asd() {
	system("leaks intern");
}

int main() {
	try {
		Intern intern;
		Bureaucrat a("a", 1);

		// std::cout << "----- Test: Shrubbery------\n\n";
		// AForm* shrub = intern.makeForm("shrubbery creation", "shrub");
		// std::cout << shrub << "\n" << *shrub << "\n";

		// a.signForm(*shrub);
		// std::cout << *shrub << "\n";
		// a.executeForm(*shrub);
		// delete shrub;


		// std::cout << "----- Test: Robotomy------\n\n";
		// AForm* robo = intern.makeForm("robotomy requset", "robo");
		// std::cout << robo << "\n" << *robo << "\n";

		// a.signForm(*robo);
		// std::cout << *robo << "\n";
		// a.executeForm(*robo);
		// delete robo;


		// std::cout << "----- Test: Pardon------\n\n";
		// AForm* president = intern.makeForm("presidential pardon", "president");
		// std::cout << president << "\n" << *president << "\n";

		// a.signForm(*president);
		// std::cout << *president << "\n";
		// a.executeForm(*president);
		// delete president;


	} catch (const Bureaucrat::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const Bureaucrat::gradeTooLowException& e) {
		std::cout << e.what();
	} catch (const AForm::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const AForm::gradeTooLowException& e) {
		std::cout << e.what();
	}

	asd();

	return 0;
}