#include <iostream>

static void charToChar(char c);
static void charToInt(char c);
static void charToFloat(char c);
static void charToDouble(char c);

// 문자로 들어온 후 오버플로우 발생할 일 없음
void fromChar(const std::string& str) {
	char	c = *str.c_str();

	charToChar(c);
	charToInt(c);
	std::cout.precision(1);
	std::cout << std::fixed;
	charToFloat(c);
	charToDouble(c);
	std::cout << std::defaultfloat;
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
