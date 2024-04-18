#include "../incs/RPN.hpp"

RPN::RPN(unsigned int N) : max_size(N) {
	std::cout << "[OCCF] RPN constructor called\n";
}

RPN::~RPN(void) {
	std::cout << "[OCCF] RPN destructor called\n";
}

RPN::RPN(const RPN& obj) : arr(obj.arr), max_size(obj.max_size) {
	std::cout << "[OCCF] RPN copy constructor called\n";
}

RPN& RPN::operator= (const RPN& obj) {
	std::cout << "[OCCF] RPN copy assignment operator called\n";

	if (this != &obj) {
		arr = obj.arr;
		max_size = obj.max_size;
	}

	return *this;
}

int RPN::operator[] (unsigned int idx) {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

int RPN::operator[] (unsigned int idx) const {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

unsigned int RPN::getMaxSize(void) { return max_size; }

void RPN::addNumber(int n) {
	if (arr.size() == max_size)
		throw std::out_of_range("Array capacity exceeded");
	if (checkOverlap(n) == true)
		throw std::invalid_argument("Element is overlaped");
	arr.push_back(n);
}

void RPN::fillNumbers(unsigned int len) {
	if (len + arr.size() > max_size)
		throw std::out_of_range("Array capacity exceeded");

	for (unsigned int i = 0; i < len; i++) {
		if (checkOverlap(i) == true)
			len++;
		else
			arr.push_back(i);
	}
}

int RPN::shortestRPN(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int min = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		min = min < tmp ? min : tmp;
	}

	return min;
}

int RPN::longestRPN(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int max = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		max = max > tmp ? max : tmp;
	}

	return max;
}

bool RPN::checkOverlap(int n) {
	iter it = arr.begin();
	iter ite = arr.end();

	while (it != ite) {
		if (*it == n)
			return true;
		it++;
	}
	return false;
}

void RPN::printNums(void) {
	std::cout << "nums: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
