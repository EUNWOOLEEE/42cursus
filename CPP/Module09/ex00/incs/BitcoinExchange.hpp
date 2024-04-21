#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <exception>
# include <string>
# include <deque>
# include <map>
# include <ctime>
# include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange(char* file_name);
		~BitcoinExchange(void);

		void	readDatabase(void);
		void	readInputFile(void);
		void	calInputValue(std::string& date, double value);
		bool	checkDateForm(const std::string& date);
		bool	isValidDate(const int year, const int month, const int day);

		std::deque<std::string> split(const std::string& str, const char delimiter);

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);

		BitcoinExchange& operator= (const BitcoinExchange& obj);

		std::ifstream					database_file;
		std::ifstream					input_file;
		std::map<std::string, double>	database;
		std::string						oldest_date;
};

#endif