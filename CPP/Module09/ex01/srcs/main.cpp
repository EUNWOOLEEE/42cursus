#include "../incs/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"Reverse polish notation expression\"\n";
		return 0;
	}

	try {
		RPN			rpn(argv[1]);
		std::string	token;

		while ((token = rpn.getNextToken()).size()) {
			if (rpn.isOperator(token) == true)
				rpn.calculate(token[0]);
			else
				rpn.pushToStack(token);
		}

		rpn.printResult();

	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	} catch (const std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}