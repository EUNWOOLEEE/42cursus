#include <iostream>

void intToChar(int i) {
	if ((0 <= i && i <= 31) || i == 127)
		std::cout << "char: non displayable\n";
	else if (i < 0 || 127 < i)
		std::cout << "char: impossible\n";
	else {
		char c = static_cast<char>(i);
		std::cout << "char: '" << c << "'\n";
	}
}

void intToInt(int i) {
	std::cout << "int: " << i << "\n";
}

void intToFloat(int i) {
	float f = static_cast<float>(i);
	std::cout << "float: " << f << "f" << "\n";
}

void intToDouble(int i) {
	double d = static_cast<double>(i);
	std::cout << "double: " << d << "\n";
}