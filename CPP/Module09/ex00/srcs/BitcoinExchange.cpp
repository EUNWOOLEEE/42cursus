#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char* file_name) : database_file("data.csv"), input_file(file_name) {
	std::cout << "[OCCF] BitcoinExchange constructor called\n";

	if (input_file.is_open() == false)
		throw std::runtime_error("could not open input file.");
	if (input_file.peek() == EOF)
		throw std::runtime_error("input file is empty.");
	if (database_file.is_open() == false)
		throw std::runtime_error("could not open database file.");
	if (database_file.peek() == EOF)
		throw std::runtime_error("database file is empty.");
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "[OCCF] BitcoinExchange destructor called\n";
}

void BitcoinExchange::readDatabase(void) {
	Mylist		tokens;
	std::string	line, date, remain;
	double		value;
	char*		remain_c_str;

	std::getline(database_file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid database file format.");

	while (std::getline(database_file, line)) {
		tokens = split(line, ',');

		if (tokens.size() != 2)
			throw std::runtime_error("invalid database file format.");

		date = tokens[0];
		value = strtod(tokens[1].c_str(), &remain_c_str);
		remain = std::string(remain_c_str);
	
		if (checkDateForm(date) == false					\
			|| (remain != "f" && remain.size())				\
			|| (remain == "f" && tokens[1].size() == 1)		\
			|| value < 0)
			throw std::runtime_error("invalid database file format.");

		database[date] = value;
	}

	oldest_date = database.begin()->first;
}

void BitcoinExchange::readInputFile(void) {
	Mylist		tokens;
	std::string	line, date, remain;
	double		value;
	char*		remain_c_str;
	
	std::getline(input_file, line);
	if (line != "date | value")
		throw std::runtime_error("invalid input file format.");

	while (std::getline(input_file, line)) {
		tokens = split(line, ' ');
		
		if (tokens.size() != 3) {
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}

		date = tokens[0];
		value = strtod(tokens[2].c_str(), &remain_c_str);
		remain = std::string(remain_c_str);
	
		if (checkDateForm(date) == false || date < oldest_date)
			std::cout << "Error: bad input => " << date << "\n";

		else if (tokens[1] != "|")
			std::cout << "Error: bad input => " << tokens[1] << "\n";

		else if ((remain != "f" && remain.size())						\
				|| (remain == "f" && tokens[1].size() == 1))			\
			std::cout << "Error: bad input => " << tokens[2] << "\n";

		else if (value < 0)
			std::cout << "Error: not a positive number.\n";

		else if (1000 < value)
			std::cout << "Error: too large a number.\n";

		else
			calInputValue(date, value);
	}
}

void BitcoinExchange::calInputValue(std::string& date, double value) {
	std::map<std::string, double>::iterator	it = database.begin();
	std::map<std::string, double>::iterator	ite = database.end();
	double									rate;

	if (database[date])
		rate = database[date];
	else {
		while (it != ite && it->first < date)
			it++;
		rate = database[(--it)->first];
	}
		
	std::cout << date << " => " << value << " = " << value * rate << "\n";
}

bool BitcoinExchange::checkDateForm(const std::string& date) {
	if (date.size() != 10)
		return false;

	for (unsigned int i = 0; i < date.size(); i++)
		if (isdigit(date[i]) == false && date[i] != '-')
			return false;

	Mylist	tokens = split(date, '-');

	if (tokens.size() != 3									\
		|| isValidDate(atoi(tokens[0].c_str()),				\
						atoi(tokens[1].c_str()),			\
						atoi(tokens[2].c_str())) == false)
		return false;
	return true;
}

bool BitcoinExchange::isValidDate(const int year, const int month, const int day) {
	time_t		rawtime = time(NULL);
	struct tm*	timeinfo = localtime(&rawtime);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	timeinfo->tm_isdst = -1;

	mktime(timeinfo);

	// std::cout << "\n\nPrint date\n";
	// std::cout << "year: " << year << ", " << timeinfo->tm_year + 1900 << "\n";
	// std::cout << "month: " << month << ", " << timeinfo->tm_mon + 1 << "\n";
	// std::cout << "day: " << day << ", " << timeinfo->tm_mday << "\n\n";

	if (year != timeinfo->tm_year + 1900	\
		|| month != timeinfo->tm_mon + 1	\
		|| day != timeinfo->tm_mday) {
		return false;
	}
	else
		return true;
}

Mylist BitcoinExchange::split(const std::string& str, const char delimiter) {
	Mylist				tokens;
	std::string			token;
	std::stringstream	ss(str);

	while (std::getline(ss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}
