#include "../incs/ScalarConverter.hpp"
#include <iostream>
#include <float.h>

static void doubleToChar(double d);
static void doubleToInt(double d);
static void doubleToFloat(double d);
static void doubleToDouble(double d);

bool fromDouble(const std::string& str) {
	double	d = strtod(str.c_str(), NULL);
	int		digits = checkDecimalDigits(str);

	digits = digits == 0 ? 1 : digits;

	doubleToChar(d);
	doubleToInt(d);
	std::cout.precision(digits);
	std::cout << std::fixed;
	doubleToFloat(d);
	doubleToDouble(d);
	std::cout << std::defaultfloat;
}

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
	if (d < INT_MIN || INT_MAX < d)
		std::cout << "char: impossible\n";
	else {
		int i = static_cast<int>(d);
		std::cout << "int: " << i << "\n";
	}
}

void doubleToFloat(double d) {
	if (d < FLT_MIN || FLT_MAX < d)
		std::cout << "char: impossible\n";
	else {
		float f = static_cast<float>(d);
		std::cout << "float: " << f << "f" << "\n";
	}
}

void doubleToDouble(double d) {
	std::cout << "double: " << d << "\n";
}
