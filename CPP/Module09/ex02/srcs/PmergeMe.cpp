#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(unsigned int N) : max_size(N) {
	std::cout << "[OCCF] PmergeMe constructor called\n";
}

PmergeMe::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

PmergeMe::PmergeMe(const PmergeMe& obj) : arr(obj.arr), max_size(obj.max_size) {
	std::cout << "[OCCF] PmergeMe copy constructor called\n";
}

PmergeMe& PmergeMe::operator= (const PmergeMe& obj) {
	std::cout << "[OCCF] PmergeMe copy assignment operator called\n";

	if (this != &obj) {
		arr = obj.arr;
		max_size = obj.max_size;
	}

	return *this;
}

int PmergeMe::operator[] (unsigned int idx) {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

int PmergeMe::operator[] (unsigned int idx) const {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

unsigned int PmergeMe::getMaxSize(void) { return max_size; }

void PmergeMe::addNumber(int n) {
	if (arr.size() == max_size)
		throw std::out_of_range("Array capacity exceeded");
	if (checkOverlap(n) == true)
		throw std::invalid_argument("Element is overlaped");
	arr.push_back(n);
}

void PmergeMe::fillNumbers(unsigned int len) {
	if (len + arr.size() > max_size)
		throw std::out_of_range("Array capacity exceeded");

	for (unsigned int i = 0; i < len; i++) {
		if (checkOverlap(i) == true)
			len++;
		else
			arr.push_back(i);
	}
}

int PmergeMe::shortestPmergeMe(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int min = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		min = min < tmp ? min : tmp;
	}

	return min;
}

int PmergeMe::longestPmergeMe(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int max = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		max = max > tmp ? max : tmp;
	}

	return max;
}

bool PmergeMe::checkOverlap(int n) {
	iter it = arr.begin();
	iter ite = arr.end();

	while (it != ite) {
		if (*it == n)
			return true;
		it++;
	}
	return false;
}

void PmergeMe::printNums(void) {
	std::cout << "nums: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
