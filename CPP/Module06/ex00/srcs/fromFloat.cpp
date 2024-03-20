#include <iostream>

void floatToChar(float f) {
	if ((0 <= f && f <= 31) || f == 127)
		std::cout << "char: non displayable\n";
	else if (f < 0 || 127 < f)
		std::cout << "char: impossible\n";
	else {
		char c = static_cast<char>(f);
		std::cout << "char: '" << c << "'\n";
	}
}

void floatToInt(float f) {
	int i = static_cast<int>(f);
	std::cout << "int: " << i << "\n";
}

void floatToFloat(float f) {
	std::cout << "float: " << f << "f" << "\n";
}

void floatToDouble(float f) {
	double d = static_cast<double>(f);
	std::cout << "double: " << d << "\n";
}
