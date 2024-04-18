#include "../incs/BitcoinExchange.hpp"


int	main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Usage: ./btc input.txt\n";

	try {
		BitcoinExchange btc(argv[1]);
	} catch (const std::ios_base::failure& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	
	return 0;
}