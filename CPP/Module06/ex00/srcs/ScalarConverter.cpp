#include "../incs/ScalarConverter.hpp"

/*
	char: a, !, +, -a, +a, aa
	int: 0, 32, 42, +42, -42, 127, 128
	float: 0.2f, 32.3f, 42.4f, +42.5f, -42.6f, 127.7f, 128.0f
	double: remove suffix 'f'
	pseudo: -inff, +inff, nanf, -inf, +inf, nan
*/

int checkType(const std::string& str);
int checkDecimalDigits(const std::string& str);

//변환 함수 확인하기
void ScalarConverter::convert(std::string str) {
	int type = checkType(str);

	if (type == -1)
		std::cout << "non-valid input\n";

	else if (type == 1) {
		char	c = *str.c_str();

		charToChar(c);
		charToInt(c);
		std::cout.precision(1);
		std::cout << std::fixed;
		charToFloat(c);
		charToDouble(c);
		std::cout << std::defaultfloat;
	}

	else if (type == 2) {
		int		i = strtol(str.c_str(), NULL, 10);

		intToChar(i);
		intToInt(i);
		std::cout.precision(1);
		std::cout << std::fixed;
		intToFloat(i);
		intToDouble(i);
		std::cout << std::defaultfloat;
	}

	else if (type == 3) {
		float	f = atof(str.c_str());
		int		digits = checkDecimalDigits(str) - 1;

		floatToChar(f);
		floatToInt(f);
		std::cout.precision(digits);
		std::cout << std::fixed;
		floatToFloat(f);
		floatToDouble(f);
		std::cout << std::defaultfloat;
	}

	else if (type == 4) {
		double	d = strtod(str.c_str(), NULL);
		int		digits = checkDecimalDigits(str);

		doubleToChar(d);
		doubleToInt(d);
		std::cout.precision(digits);
		std::cout << std::fixed;
		doubleToFloat(d);
		doubleToDouble(d);
		std::cout << std::defaultfloat;
	}

	else if (type == 5) {
		pseudoToChar();
		pseudoToInt();
		pseudoToFloat(str);
		pseudoToDouble(str);
	}
}

int checkType(const std::string& str) {
	// double max를 넘으면? 오버플로랑 변함이 의미 없을 때 처리하기
	
	try {
		if (str == "inff" || str == "inf"		\
			|| str == "-inff" || str == "-inf"	\
			|| str == "+inff" || str == "+inf"	\
			|| str == "nanf" || str == "nan"	\
			|| str == "-nanf" || str == "-nan"	\
			|| str == "+nanf" || str == "+nan")
			return 5;

		stod(str);

		if (str.find('.') != std::string::npos) {
			if (str[str.length() - 1] == 'f')
				return 3;
			return 4;
		}
		// if 
		return 2;

	} catch (const std::exception& e) {
		if (str.length() == 1)
			return 1;
	}
	
	return -1;
}

int checkDecimalDigits(const std::string& str) {
	size_t pos = str.find(".");

	return str.length() - pos - 1;
}