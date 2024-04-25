#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	PmergeMe pmm(argc - 1, &argv[1]);

	pmm.sortVector();
		
	return 0;
}