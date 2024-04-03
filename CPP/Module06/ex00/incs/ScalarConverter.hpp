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

int 	checkType(const std::string& str);
int 	checkDecimalDigits(const std::string& str);

void	fromChar(const std::string& str);
void	fromInt(const std::string& str);
void	fromFloat(const std::string& str);
void	fromDouble(const std::string& str);
void	fromPseudo(const std::string& str);

#endif