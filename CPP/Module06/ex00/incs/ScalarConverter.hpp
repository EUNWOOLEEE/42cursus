#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <stdlib.h>

class ScalarConverter {
	public:
		static void convert(const std::string str);

	private:
		ScalarConverter(void);
};

// typedef struct value_s {
// 	char	character;
// 	int		integer;
// 	float	decimal_float;
// 	double	decimal_double;
// } value_t;

int 	checkType(const std::string& str);
int 	checkDecimalDigits(const std::string& str);

bool	fromChar(const std::string& str);
bool	fromInt(const std::string& str);
bool	fromFloat(const std::string& str);
bool	fromDouble(const std::string& str);
bool	fromPseudo(const std::string& str);

// bool	fromChar(const std::string& str, value_t& values);
// bool	fromInt(const std::string& str, value_t& values);
// bool	fromFloat(const std::string& str, value_t& values);
// bool	fromDouble(const std::string& str, value_t& values);
// bool	fromPseudo(const std::string& str, value_t& values);

#endif