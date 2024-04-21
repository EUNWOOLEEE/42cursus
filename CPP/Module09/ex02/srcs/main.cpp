#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	try {
		PmergeMe pmm(argc - 1, &argv[1]);
	}
		
	return 0;
}