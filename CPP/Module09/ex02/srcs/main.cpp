#include "../incs/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	try {
		
		PmergeMe< std::vector< std::pair<int, int> > > pmmv(argc, argv, "vector");
		pmmv.sort();
		PmergeMe< std::deque< std::pair<int, int> > > pmmd(argc, argv, "deque");
		pmmd.sort();

	} catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}