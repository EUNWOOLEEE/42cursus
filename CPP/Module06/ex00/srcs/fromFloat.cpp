#include "../incs/ScalarConverter.hpp"
#include <iostream>
#include <float.h>

static void floatToChar(float f);
static void floatToInt(float f);
static void floatToFloat(float f);
static void floatToDouble(float f);

bool fromFloat(const std::string& str) {
	float	f = atof(str.c_str());
	int		digits = checkDecimalDigits(str) - 1;

	digits = digits == 0 ? 1 : digits;

	floatToChar(f);
	floatToInt(f);
	std::cout.precision(digits);
	std::cout << std::fixed;
	floatToFloat(f);
	floatToDouble(f);
	std::cout << std::defaultfloat;
}

// bool checkValid(const std::string& str) {
// 	double d = strtod(str.c_str(), NULL);
	
// 	if (d < FLT_MIN || FLT_MAX < d)
// 		return false;
// 	return true;
// }

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
	if (f < INT_MIN || INT_MAX < f)
		std::cout << "char: impossible\n";
	else {
		int i = static_cast<int>(f);
		std::cout << "int: " << i << "\n";
	}
}

void floatToFloat(float f) {
	std::cout << "float: " << f << "f" << "\n";
}

void floatToDouble(float f) {
	double d = static_cast<double>(f);
	std::cout << "double: " << d << "\n";
}
