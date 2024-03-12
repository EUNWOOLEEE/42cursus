#include "../incs/Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 149);
		std::cout << a << "\n" << b << "\n";

		// std::cout << "------------ Test: adjust grade ------------\n";
		// a.incGrade();
		// b.decGrade();
		// std::cout << a << "\n" << b << "\n";

		// std::cout << "------------ Test: copy ------------\n";
		// Bureaucrat c(a);
		// Bureaucrat d("d", 1);
		// d = b;
		// std::cout << c << "\n" << d << "\n";

		// std::cout << "------------ Test: out of range ------------\n";
		// a.incGrade();
		// a.incGrade();
		// b.decGrade();
		// b.decGrade();
		// std::cout << a << "\n" << b << "\n";

		// std::cout << "------------ Test: invalid argument ------------\n";
		// Bureaucrat c("c", 0);
		// Bureaucrat d("d", 151);

	} catch (const Bureaucrat::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const Bureaucrat::gradeTooLowException& e) {
		std::cout << e.what();
	}

	
	return 0;
}