#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <stdlib.h>

class ScalarConverter {
	public:
		static void convert(std::string str);

	private:
		ScalarConverter(void);
};

void	charToChar(char c);
void	charToInt(char c);
void	charToFloat(char c);
void	charToDouble(char c);

void	intToChar(int c);
void	intToInt(int c);
void	intToFloat(int c);
void	intToDouble(int c);

void	floatToChar(float f);
void	floatToInt(float f);
void	floatToFloat(float f);
void	floatToDouble(float f);

void	doubleToChar(double d);
void	doubleToInt(double d);
void	doubleToFloat(double d);
void	doubleToDouble(double d);

void	pseudoToChar(void);
void	pseudoToInt(void);
void	pseudoToFloat(std::string p);
void	pseudoToDouble(std::string p);

#endif