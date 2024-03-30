#include "../incs/ScalarConverter.hpp"

/*
	char: a, !, +, -a, +a, aa
	int: 0, 32, 42, +42, -42, 127, 128, 2147483647
	float: 0.2f, 32.3f, 42.4f, +42.5f, -42.6f, 127.7f, 128.f .5f
	double: remove suffix 'f'
	pseudo: inff, -inff, +inff, nanf, -nanf, +nanf, 
			inf, -inf, +inf, nan, -nan, +nan
*/

void ScalarConverter::convert(const std::string str) {
	int		type = checkType(str);
	bool	(*fp[5])(const std::string&) = {	fromChar, 	\
												fromInt,	\
												fromFloat,	\
												fromDouble,	\
												fromPseudo};

	// std::cout << "check type: " << type << "\n";

	if (type == -1 || fp[type](str) == false)
		std::cout << "non-valid input\n";
}

int checkType(const std::string& str) {
	if (str == "inff" || str == "inf"		\
		|| str == "-inff" || str == "-inf"	\
		|| str == "+inff" || str == "+inf"	\
		|| str == "nanf" || str == "nan"	\
		|| str == "-nanf" || str == "-nan"	\
		|| str == "+nanf" || str == "+nan")
		return 4;

	bool sign, dot, f;
	sign = dot = f = false;

	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			if (sign == true || i != 0)
				return -1;
			sign = true;
		}
		else if (str[i] == '.') {
			if (dot == true)
				return -1;
			dot = true;
		}
		else if (str[i] == 'f') {
			if (i != str.length() - 1)
				return -1;
			f = true;
		}
		else if (str[i] < '0' || '9' < str[i]) {
			if (str.length() != 1)
				return -1;
			return 0;
		}
	}
	
	if (sign == true && str.length() == 1)
		return 0;
	if (f == true) {
		if (dot == false)
			return -1;
		return 2;
	}
	if (dot == true)
		return 3;
	return 1;
}

int checkDecimalDigits(const std::string& str) {
	size_t pos = str.find(".");
	return str.length() - pos - 1;
}
