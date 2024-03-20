#include <iostream>

void charToChar(char c) {
	std::cout << "char: '" << c << "'\n";
}

void charToInt(char c) {
	int i = static_cast<int>(c);
	std::cout << "int: " << i << "\n";
}

void charToFloat(char c) {
	float f = static_cast<float>(c);
	std::cout << "float: " << f << "f" << "\n";
}

void charToDouble(char c) {
	double d = static_cast<double>(c);
	std::cout << "double: " << d << "\n";
}
