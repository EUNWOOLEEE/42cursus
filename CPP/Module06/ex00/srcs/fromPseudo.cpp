#include <iostream>

void pseudoToChar(void) {
	std::cout << "char: impossible\n";
}

void pseudoToInt(void) {
	std::cout << "int: impossible\n";
}

void pseudoToFloat(std::string p) {
	if (p == "-inf" || p == "+inf" || p == "nan")
		std::cout << "float: " << p << "f\n";
	else
		std::cout << "float: " << p << "\n";
}

void pseudoToDouble(std::string p) {
	if (p == "-inff" || p == "+inff" || p == "nanf")
		std::cout << "double: " << p.substr(0, p.length() - 1) << "\n";
	else
		std::cout << "double: " << p << "\n";
}