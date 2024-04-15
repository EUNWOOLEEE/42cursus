#include "../incs/Span.hpp"

Span::Span(unsigned int N) : max_size(N) {
	std::cout << "[OCCF] Span constructor called\n";
}

Span::~Span(void) {
	std::cout << "[OCCF] Span destructor called\n";
}

Span::Span(const Span& obj) : arr(obj.arr), max_size(obj.max_size) {
	std::cout << "[OCCF] Span copy constructor called\n";
}

Span& Span::operator= (const Span& obj) {
	std::cout << "[OCCF] Span copy assignment operator called\n";

	if (this != &obj) {
		arr = obj.arr;
		max_size = obj.max_size;
	}

	return *this;
}

int Span::operator[] (unsigned int idx) {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

int Span::operator[] (unsigned int idx) const {
	if (idx >= arr.size())
		throw std::out_of_range("Out of range");
	return arr[idx];
}

unsigned int Span::getMaxSize(void) { return max_size; }

void Span::addNumber(int n) {
	if (arr.size() == max_size)
		throw std::out_of_range("Array capacity exceeded");
	if (checkOverlap(n) == true)
		throw std::invalid_argument("Element is overlaped");
	arr.push_back(n);
}

void Span::fillNumbers(unsigned int len) {
	if (len + arr.size() > max_size)
		throw std::out_of_range("Array capacity exceeded");

	for (unsigned int i = 0; i < len; i++) {
		if (checkOverlap(i) == true)
			len++;
		else
			arr.push_back(i);
	}
}

int Span::shortestSpan(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int min = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		min = min < tmp ? min : tmp;
	}

	return min;
}

int Span::longestSpan(void) {
	if (arr.size() <= 1)
		throw std::out_of_range("Lack of element");

	int max = abs(arr[0] - arr[1]);
	for (unsigned int i = 1; i < arr.size() - 1; i++) {
		int tmp = abs(arr[i] - arr[i + 1]);
		max = max > tmp ? max : tmp;
	}

	return max;
}

bool Span::checkOverlap(int n) {
	iter it = arr.begin();
	iter ite = arr.end();

	while (it != ite) {
		if (*it == n)
			return true;
		it++;
	}
	return false;
}

void Span::printNums(void) {
	std::cout << "nums: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
