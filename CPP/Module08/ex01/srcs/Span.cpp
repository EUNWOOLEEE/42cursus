#include "../incs/Span.hpp"

Span::Span(unsigned int N) : max_size(N) {
	std::cout << "[OCCF] Span constructor called\n";
}

Span::~Span(void) {
	std::cout << "[OCCF] Span destructor called\n";
}

Span::Span(const Span& obj) : nums(obj.nums), max_size(obj.max_size) {
	std::cout << "[OCCF] Span copy constructor called\n";
}

Span& Span::operator= (const Span& obj) {
	std::cout << "[OCCF] Span copy assignment operator called\n";

	if (this != &obj) {
		nums = obj.nums;
		max_size = obj.max_size;
	}
	return *this;
}

unsigned int Span::getMaxSize(void) { return max_size; }
unsigned int Span::getCurSize(void) { return nums.size(); }

void Span::addNumber(int n) {
	if (nums.size() == max_size)
		throw std::out_of_range("Set capacity exceeded");
	if (nums.find(n) != nums.end())
		throw std::invalid_argument("Element is overlaped");
	nums.insert(n);
}

void Span::fillNumbers(iter begin, iter end, size_t len) {
	if (nums.size() + len > max_size)
		throw std::out_of_range("Set capacity exceeded");

	nums.insert(begin, end);
}

int Span::shortestSpan(void) {
	if (nums.size() <= 1)
		throw std::out_of_range("Lack of element");

	size_t	min = longestSpan();

	for (iter it = nums.begin(); std::next(it) != nums.end(); it++) {
		size_t	tmp = *(std::next(it)) - *it;
		min = min < tmp ? min : tmp;
	}

	return min;
}

int Span::longestSpan(void) {
	if (nums.size() <= 1)
		throw std::out_of_range("Lack of element");

	return *(nums.rbegin()) - *(nums.begin());
}

void Span::printNums(void) {
	std::cout << "nums: ";
	for (iter it = nums.begin(); it != nums.end(); it = std::next(it))
		std::cout << *it << " ";
	std::cout << "\n";
}
