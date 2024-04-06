#include "../incs/ScalarConverter.hpp"
#include <errno.h>
#include <cstring>
#include <float.h>
#include <cmath>
#include <climits>

/*
	char: a, !, +, -a, +a, aa
	int: 0, 32, 42, +42, -42, 127, 128, 2147483647
	float: 0.2f, 32.3f, 42.4f, +42.5f, -42.6f, 127.7f, 128.f .5f
	double: remove suffix 'f'
	pseudo: inff, -inff, +inff, nanf, -nanf, +nanf, 
			inf, -inf, +inf, nan, -nan, +nan
*/

static int 	checkType(const std::string& str, double& value);
static int	checkRange(int type, double value);
static int	checkValid(int type, double value);
static void setDecimalDigits(const std::string& str, int type);
static void	fromChar(const std::string& str, double value);
static void	fromInt(const std::string& str, double value);
static void	fromFloat(const std::string& str, double value);
static void	fromDouble(const std::string& str, double value);
static void	fromPseudo(const std::string& str, double value);

void ScalarConverter::convert(const std::string str) {
	double	value = 0;
	int		type = checkType(str, value);
	void	(*fp[5])(const std::string&, double) = {	fromChar, 	\
														fromInt,	\
														fromFloat,	\
														fromDouble,	\
														fromPseudo};

	if (type == INVALID)
		std::cout << "Invalid input\n";
	else {
		setDecimalDigits(str, type);
		fp[type](str, value);
		std::cout.unsetf(std::ios::fixed);
	}
}

int checkType(const std::string& str, double& value) {

	char*	remain = NULL;
	value = strtod(str.c_str(), &remain);
	
	if (errno == ERANGE)
		return INVALID;

	if (std::isnan(value) || std::isinf(value))
		return PSEUDO;

	if (*remain != '\0') {
		if (std::strcmp(remain, str.c_str()) == 0 && str.length() == 1)
			return CHARACTER;

		if (std::strcmp(remain, "f") == 0 && str.find('.') != std::string::npos)
			return checkRange(DECIMAL_FLOAT, value);

		return INVALID;
	}

	if (str.find('.') != std::string::npos)
		return DECIMAL_DOUBLE;

	return checkRange(INTERGER, value);
}

int checkRange(int type, double value) {
	if (type  == CHARACTER) {
		if (value < CHAR_MIN || CHAR_MAX < value)
			return INVALID;
	}
	if (type == INTERGER) {
		if (value < INT_MIN || INT_MAX < value)
			return INVALID;
	}
	
	else if (type == DECIMAL_FLOAT) {
		if (value < -FLT_MAX || FLT_MAX < value)
			return INVALID;
	}

	return type;
}

int checkValid(int type, double value) {
	if (type == CHARACTER) {
		if (checkRange(type, value) == INVALID)
			std::cout << "char: impossible\n";
		else if (std::isprint(value) == false)
			std::cout << "char: non displayable\n";
		else
			return type;
	}

	else if (type == INTERGER) {
		if (checkRange(type, value) == INVALID)
			std::cout << "int: impossible\n";
		else
			return type;
	}

	else if (type == DECIMAL_FLOAT) {
		if (checkRange(type, value) == INVALID)
			std::cout << "float: impossible\n";
		else
			return type;
	}

	return INVALID;
}

void setDecimalDigits(const std::string& str, int type) {
	if (type != DECIMAL_FLOAT && type != DECIMAL_DOUBLE) {
		std::cout.precision(1);
		std::cout << std::fixed;
		return ;
	}

	size_t	pos = str.find(".");
	int		res = str.length() - pos - 1;

	if (type == DECIMAL_FLOAT)
		res--;

	res = res == 0 ? 1 : res;
	
	std::cout.precision(res);
	std::cout << std::fixed;
}

void fromChar(const std::string& str, double value) {
	static_cast<void>(value);

	char	c = *str.c_str();

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void fromInt(const std::string& str, double value) {
	int	i = strtol(str.c_str(), NULL, 10);

	if (checkValid(CHARACTER, value) != INVALID)
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void fromFloat(const std::string& str, double value) {
	float	f = atof(str.c_str());

	if (checkValid(CHARACTER, value) != INVALID)
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	if (checkValid(INTERGER, value) != INVALID)
		std::cout << "int: " << static_cast<int>(f) << "\n";
	std::cout << "float: " << f << "f" << "\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void fromDouble(const std::string& str, double value) {
	double	d = strtod(str.c_str(), NULL);

	if (checkValid(CHARACTER, value) != INVALID)
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	if (checkValid(INTERGER, value) != INVALID)
		std::cout << "int: " << static_cast<int>(d) << "\n";
	if (checkValid(DECIMAL_FLOAT, value) != INVALID)
		std::cout << "float: " << static_cast<float>(d) << "f" << "\n";
	std::cout << "double: " << d << "\n";
}

void fromPseudo(const std::string& str, double value) {
	static_cast<void>(str);
	
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << value << "f\n";
	std::cout << "double: " << value << "\n";
}
