#include <iostream>

void doubleToChar(double d) {
	if ((0 <= d && d <= 31) || d == 127)
		std::cout << "char: non displayable\n";
	else if (d < 0 || 127 < d)
		std::cout << "char: impossible\n";
	else {
		char c = static_cast<char>(d);
		std::cout << "char: '" << c << "'\n";
	}
}

void doubleToInt(double d) {
	int i = static_cast<int>(d);
	std::cout << "int: " << i << "\n";
}

void doubleToFloat(double d) {
	float f = static_cast<float>(d);
	std::cout << "float: " << f << "f" << "\n";
}

void doubleToDouble(double d) {
	std::cout << "double: " << d << "\n";
}
