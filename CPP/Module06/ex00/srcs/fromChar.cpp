#include <iostream>

static bool checkValid(const std::string& str);
static void charToChar(char c);
static void charToInt(char c);
static void charToFloat(char c);
static void charToDouble(char c);

bool fromChar(const std::string& str) {
	if (checkValid(str) == false)
		return false;

	char	c = *str.c_str();

	charToChar(c);
	charToInt(c);
	std::cout.precision(1);
	std::cout << std::fixed;
	charToFloat(c);
	charToDouble(c);
	std::cout << std::defaultfloat;
	
	return true;
}

bool checkValid(const std::string& str) {
	int i = strtol(str.c_str(), NULL, 10);
	
	if (i < CHAR_MIN || CHAR_MAX < i)
		return false;
	return true;
}

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
