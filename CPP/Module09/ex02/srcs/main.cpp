#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	try {
		PmergeMe pmm;
		pmm.runVec(argc, argv);
		pmm.runDeq(argc, argv);

	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}