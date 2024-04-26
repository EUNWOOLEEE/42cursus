#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	try {
		PmergeMe< std::vector< pii > > pmmv(argc, argv, "vector");
		pmmv.run();
		PmergeMe< std::deque< pii > > pmmd(argc, argv, "deque");
		pmmd.run();

	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}