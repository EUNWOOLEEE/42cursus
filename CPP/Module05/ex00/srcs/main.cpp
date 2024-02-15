#include "../incs/bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 149);
		std::cout << a << b;
		a.incGrade();
		b.decGrade();
		std::cout << a << b;

		// std::cout << "------------test out of range------------\n";
		// a.incGrade();
		// b.decGrade();
		// std::cout << a << b;

		// std::cout << "------------test invalid argument------------\n";
		// Bureaucrat a("a", 0);
		// Bureaucrat a("a", 151);

	} catch (Bureaucrat::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (Bureaucrat::gradeTooLowException& e) {
		std::cout << e.what();
	}

	
	return 0;
}