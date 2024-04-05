#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <stdlib.h>

typedef enum e_type {
	INVALID = -1,
	CHARACTER,
	INTERGER,
	DECIMAL_FLOAT,
	DECIMAL_DOUBLE,
	PSEUDO
} t_type;

class ScalarConverter {
	public:
		static void convert(const std::string str);

	private:
		ScalarConverter(void);
};

#endif