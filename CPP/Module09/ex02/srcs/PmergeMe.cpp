#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(int _num_count, char** _nums) : num_count(_num_count), nums(_num_count) {
	std::cout << "[OCCF] PmergeMe constructor called\n";

	for (size_t i = 0; i < num_count; i++)
		nums[i] = atoi(_nums[i]);
}

PmergeMe::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}
