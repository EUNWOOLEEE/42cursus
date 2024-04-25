#include "../incs/Pvector.hpp"
#include "../incs/Pdeque.hpp"

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMxe n1 n2 n...\n";
		return 0;
	}

	Pvector pmm(argc - 1, &argv[1]);

	pmm.sort(argc, argv);
		
	return 0;
}