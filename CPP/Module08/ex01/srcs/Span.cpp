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
unsigned int Span::getCurSize(void) { return arr.size(); }

void Span::addNumber(int n) {
	if (arr.size() == max_size)
		throw std::out_of_range("Array capacity exceeded");
	if (checkOverlap(n) == true)
		throw std::invalid_argument("Element is overlaped");
	arr.push_back(n);
}

void Span::fillNumbers(iter begin, iter end, size_t len) {
	if (arr.size() + len > max_size)
		throw std::out_of_range("Array capacity exceeded");

	while (begin != end) {
		if (checkOverlap(*begin) == false)
			arr.push_back(*begin);
		begin++;
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

	if (std::find(it, ite, n) != ite)
		return true;
	return false;
}

void Span::printNums(void) {
	iter it = arr.begin();
	iter ite = arr.end();

	std::cout << "nums: ";
	while (it != ite)
		std::cout << *it++ << " ";
	std::cout << "\n";
}
