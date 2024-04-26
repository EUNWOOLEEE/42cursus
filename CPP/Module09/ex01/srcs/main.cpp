#include "../incs/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./RPN \"Reverse polish notation expression\"\n";
		return 0;
	}

	try {
		RPN	rpn(argv[1]);
		rpn.run();
		
	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	} catch (const std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}