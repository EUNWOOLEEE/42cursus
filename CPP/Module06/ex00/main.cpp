#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2)
		return 0;

	char* pos;
	double n = strtod(argv[1], &pos);
	std::cout << "n: " << n << ", pos: " << pos << "\n";

	// ScalarConverter::convert(std::string(argv[1]));
	return 0;
}
