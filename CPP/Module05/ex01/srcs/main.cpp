#include "../incs/Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 149);
		std::cout << a << "\n" << b << "\n";

		Form c("c", 1, 1);
		Form d("d", 150, 150);
		std::cout << c << "\n" << d << "\n";


		// std::cout << "----- Test: sign success and fail------\n\n";
		// a.signForm(c);
		// b.signForm(d);
		// std::cout << c << "\n" << d << "\n";

		// a.incGrade();
		// b.decGrade();
		// std::cout << a << "\n" << b << "\n";

		// a.signForm(c);
		// b.signForm(d);
		// std::cout << c << "\n" << d << "\n";


		// std::cout << "------------ Test: copy ------------\n";
		// Form e(c);
		// Form f("f", 1, 1);
		// f = d;
		// std::cout << e << "\n" << f << "\n";


		// std::cout << "----- Test: invalid argument ------\n\n";
		// Form e("e", 0, 1);
		// Form f("f", 150, 151);


	} catch (const Bureaucrat::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const Bureaucrat::gradeTooLowException& e) {
		std::cout << e.what();
	} catch (const Form::gradeTooHighException& e) {
		std::cout << e.what();
	} catch (const Form::gradeTooLowException& e) {
		std::cout << e.what();
	}

	return 0;
}