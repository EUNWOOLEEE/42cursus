#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <exception>
# include <ctime>
# include <vector>
# include <deque>

typedef std::pair<int, int> pii;

template <typename T>
class PmergeMe {
	public:
		PmergeMe(int argc, char** argv, std::string _type);
		~PmergeMe(void);

		void	run(void);
		void	init(char** _nums);
		void	divide(T& main, T& sub);
		void	insert(T& main, T& sub);
		int		searchSetIdx(T& main, int idx) const;
		int		binarySearch(T& main, int idx, int values);
		int		calJacobsthal(int n);

		// utils
		int		convertNum(char* num_str) const;
		void	printBeforeNums(char** _nums) const;
		void	printAfterNums(T& main) const;
		void	printTime(void);

		void	printPairs(std::string str, std::string type, T pairs);

	protected:
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		std::string		type;
		clock_t			start;
		T				nums;
		size_t			num_cnt;
		unsigned int	chain_size;
		pii				last;
};

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char** argv, std::string _type) : type(_type) {
	std::cout << "[OCCF] PmergeMe constructor called\n";

	start = clock();
	num_cnt = argc - 1;
	chain_size = num_cnt / 2;
	nums = T(chain_size);
	last = std::make_pair(-1, 0);

	printBeforeNums(&argv[1]);

	init(&argv[1]);
	// printPairs("Step1: Divide into two and sort by larger", "main, sub", nums);
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

template <typename T>
void PmergeMe<T>::run(void) {
	std::sort(nums.begin(), nums.end());

	T	main(chain_size);
	T	sub(chain_size);

	divide(main, sub);

	// std::cout << "Step2: divide main and sub";
	// printPairs("", "main, index", main);
	// printPairs("", "sub, index", sub);

	insert(main, sub);

	printAfterNums(main);
	printTime();

	// printPairs("Step3: Sort", "main, index", main);
}

template <typename T>
void PmergeMe<T>::init(char** _nums) {
	for (unsigned int i = 0, j = chain_size; i < chain_size; i++, j++) {
		int	first = convertNum(_nums[i]);
		int second = convertNum(_nums[j]);

		if (first < second)
			std::swap(first, second);

		nums[i] = std::make_pair(first, second);
	}

	if (num_cnt % 2) {
		last.first = convertNum(_nums[num_cnt - 1]);
	}
}

template <typename T>
void PmergeMe<T>::divide(T& main, T& sub) {
	for (unsigned int i = 0; i < chain_size; i++) {
		main[i] = std::make_pair(nums[i].first, i);
		sub[i] = std::make_pair(nums[i].second, i);
	}
}

template <typename T>
void PmergeMe<T>::insert(T& main, T& sub) {
	unsigned int	j = 1;
	unsigned int	pre_j;
	unsigned int	j_cnt = 3;
	int				idx;

	main.insert(main.begin(), 1, sub[0]);

	while (true) {
		pre_j = j;
		j = calJacobsthal(j_cnt);
		if (j > chain_size)
			j = chain_size;

		for (unsigned int i = j; i > pre_j; i--) {
			idx = searchSetIdx(main, sub[i - 1].second);
			idx = binarySearch(main, idx, sub[i - 1].first);
			main.insert(main.begin() + idx, 1, sub[i - 1]);
		}

		if (j == chain_size)
			break;

		j_cnt++;
	}

	if (last.first != -1) {
		idx = binarySearch(main, main.size(), last.first);
		main.insert(main.begin() + idx, 1, last);
	}
}

template <typename T>
int PmergeMe<T>::searchSetIdx(T& main, int idx) const {
	for (unsigned int i = idx; i < main.size(); i++)
		if (idx == main[i].second)
			return i;
	return -1;
}

template <typename T>
int PmergeMe<T>::binarySearch(T& main, int idx, int values) {
	int	left = 0;
	int	mid;
	int	right = idx;

	while (left <= right) {
		mid = (left + right) / 2;

		if (main[mid].first > values)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

template <typename T>
int PmergeMe<T>::calJacobsthal(int n) {
	int	first = 0, second = 1, third = 1;

	if (n == 0)
		return first;
	if (n == 1)
		return second;
	if (n == 2)
		return third;

	for (int i = 3; i <= n; i++) {
		first = second;
		second = third;
		third = second + 2 * first;
	}
	return third;
}

// utils
template <typename T>
int	 PmergeMe<T>::convertNum(char* num_str) const {
	for (int i = 0; num_str[i]; i++)
		if (isdigit(num_str[i]) == false)
			throw std::runtime_error("Input values must be positive number");
	return atoi(num_str);
}

template <typename T>
void PmergeMe<T>::printBeforeNums(char** nums) const {
	std::cout << "\nBefore: ";
	for (unsigned int i = 0; i < num_cnt; i++)
		std::cout << nums[i] << " ";
	std::cout << "\n";
}

template <typename T>
void PmergeMe<T>::printAfterNums(T& main) const {
	std::cout << "After: ";
	for (unsigned int i = 0; i < main.size(); i++)
		std::cout << main[i].first << " ";
	std::cout << "\n";
}

template <typename T>
void PmergeMe<T>::printTime(void) {
	clock_t total = clock() - start;

	std::cout << "Time to process a range of " << nums.size()	\
				<< " elements with std::" << type << " : " << total << " us\n\n";
}

// Test function
template <typename T>
void PmergeMe<T>::printPairs(std::string str, std::string type, T pairs) {
	std::cout << "\n" << str << "\n";
	std::cout << type << "\n";
	for (unsigned int i = 0; i < pairs.size(); i++)
		std::cout << " < " << pairs[i].first << ", " << pairs[i].second << " >\n";
	std::cout << "\n";
}

#endif