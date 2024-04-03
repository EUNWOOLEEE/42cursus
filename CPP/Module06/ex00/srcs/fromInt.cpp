#include <iostream>

static void intToChar(int i);
static void intToFloat(int i);
static void intToDouble(int i);

// 오버플로우 발생할 수 있음
void fromInt(const std::string& str) {
	int	i = strtol(str.c_str(), NULL, 10);

	intToChar(i);

	long l = strtol(str.c_str(), NULL, 10);
	if (l < INT_MIN || INT_MAX < l)
	
	intToInt(i);

	std::cout.precision(1);
	std::cout << std::fixed;
	intToFloat(i);
	intToDouble(i);
	std::cout << std::defaultfloat;
}

bool checkValid(const std::string& str) {
		return false;
	return true;
}

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