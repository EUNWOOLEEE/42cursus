#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <exception>
# include <string>
# include <array>
# include <map>
# include <ctime>

class BitcoinExchange {
	public:
		BitcoinExchange(char* file_name);
		~BitcoinExchange(void);

		void	readDatabase(void);
		void	readFile(void);
		bool	checkLineForm(const std::string& line);
		bool	checkDateForm(const std::string& date);
		bool	checkValueRange(int value) const;

		std::array<std::string, 3>	split(const std::string& str, const char delimiter);

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);

		BitcoinExchange& operator= (const BitcoinExchange& obj);

		std::ifstream					database_file;
		std::ifstream					input_file;
		std::map<std::string, double>	databese;
		std::string						last_date;
};

#endif