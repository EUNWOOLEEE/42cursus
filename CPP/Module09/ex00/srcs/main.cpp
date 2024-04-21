#include "../incs/BitcoinExchange.hpp"


int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc input.txt\n";
		return 0;
	}

	try {
		BitcoinExchange btc(argv[1]);

		btc.readDatabase();
		btc.readInputFile();
		
	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
	
	return 0;
}