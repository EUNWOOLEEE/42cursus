#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char* file_name) : input_file(file_name), database_file("data.csv") {
	std::cout << "[OCCF] BitcoinExchange constructor called\n";

	if (input_file.is_open() == false)
		throw std::ios_base::failure("Failed to open input file");
	if (database_file.is_open() == false)
		throw std::ios_base::failure("Failed to open database");
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "[OCCF] BitcoinExchange destructor called\n";
}

void BitcoinExchange::readDatabase(void) {
	std::string	line, date;
	size_t		pos;
	double		value;

	while (std::getline(database_file, line)) {
		pos = line.find(',');
		date = line.substr(0, pos);
		value = strtod(&line.c_str()[pos], NULL);
	
		databese[date] = value;
	}
	last_date = date;
}

void BitcoinExchange::readFile(void) {
	std::string	line;
	while (std::getline(input_file, line)) {
	}
}

bool BitcoinExchange::checkLineForm(const std::string& line) {
	std::array<std::string, 3>	tokens;
	std::stringstream			ss(line);
	std::string					token;

	int i = 0;
	while (std::getline(ss, token, ' ')) {
		if (i > 2)
			return false;
		tokens[i++] = token;
	}

	if (tokens[1] != "|" || i != 2)
		return false;
}

bool BitcoinExchange::checkDateForm(const std::string& date) {
	std::array<std::string, 3>	tokens = split(date, '-');

	if (last_date < date								\
		|| strtol(tokens[1].c_str(), NULL, 10) > 12		\
		|| strtol(tokens[2].c_str(), NULL, 10) > 31)
		return false; //날짜 오류
}

bool BitcoinExchange::checkValueRange(int value) const {

}

std::array<std::string, 3> BitcoinExchange::split(const std::string& str, const char delimiter) {
	std::array<std::string, 3>	tokens;
	std::stringstream			ss(str);
	std::string					token;

	int i = 0;
	while (std::getline(ss, token, delimiter)) {
		// if (i >= 2)
		tokens[i++] = token;
	}
	return tokens;
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
// 	std::cout << "[OCCF] BitcoinExchange copy constructor called\n";
// }

// BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& obj) {
// 	std::cout << "[OCCF] BitcoinExchange copy assignment operator called\n";

// 	if (this != &obj) {
// 	}

// 	return *this;
// }
