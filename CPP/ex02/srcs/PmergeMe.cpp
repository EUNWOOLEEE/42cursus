#include "../incs/PmergeMe.hpp"

template<class container>
PmergeMe<container>::PmergeMe(int _num_cnt, char** _nums) {

	std::cout << "[OCCF] PmergeMe constructor called\n";
	
	setStartTime();

	num_cnt = _num_cnt;
	nums = container(num_cnt);
	last = std::make_pair(-1, 0);
	chain_size(num_cnt / 2);

	for (size_t i = 0; i < num_cnt; i++) {
		checkDigits(_nums[i]);
		nums[i] = atoi(_nums[i]);
	}

	jacobsthal_nums.push_back(0);
	jacobsthal_nums.push_back(1);
}

template<class container>
PmergeMe<container>::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

template<class container>
void PmergeMe<container>::checkDigits(char* num_str) const {
	for (int i = 0; num_str[i]; i++)
		if (isdigit(num_str[i]) == false)
			throw std::runtime_error("Input values must be positive number");
}

template<class container>
void PmergeMe<container>::sort(int argc, char** argv) {

	printBeforeNums();

	pii	tmp_pairs = init();
	std::sort(tmp_pairs.begin(), tmp_pairs.end());

	// printPairs("Step2: Sort by larger", "main, sub", tmp_pairs);

	pii	main(half_size);
	pii	sub(half_size);

	divide(main, sub, tmp_pairs);
	calJacobsthal();

	// std::cout << "Step3: divide main and sub";
	// printPairs("", "main, index", main);
	// printPairs("", "sub, index", sub);

	insert(main, sub);

	printAfterNums(main);
	printTime("");

	// printPairs("Step4: Sort", "main, index", main);
}

template<class container>
PmergeMe<container>::pii PmergeMe<container>::init(void) {
	if (num_count % 2)
		last.first = *(nums.rbegin());
	
	half_size = nums.size()/ 2;
	pii	tmp_pairs(half_size);

	for (unsigned int i = 0, j = half_size; i < half_size; i++, j++) {
		int	first = nums[i] > nums[j] ? nums[i] : nums[j];
		int second = nums[i] < nums[j] ? nums[i] : nums[j];

		tmp_pairs[i] = std::make_pair(first, second);
	}
	return tmp_pairs;
}

template<class container>
void PmergeMe<container>::divide(pii& main, pii& sub, pii& tmp) {
	for (unsigned int i = 0; i < half_size; i++) {
		main[i] = std::make_pair(tmp[i].first, i);
		sub[i] = std::make_pair(tmp[i].second, i);
	}
}

template<class container>
void PmergeMe<container>::insert(pii& main, pii& sub) {
	unsigned int	jacobsthal;
	unsigned int	jacobsthal_idx = 3;
	int				idx;

	main.insert(main.begin(), 1, sub[0]);

	while (jacobsthal_idx < jacobsthal_nums.size()) {
		jacobsthal = jacobsthal_nums[jacobsthal_idx];
		jacobsthal = jacobsthal > half_size ? half_size : jacobsthal;

		// std::cout << "jacobsthal: " << jacobsthal << "\n";
		for (unsigned int i = jacobsthal; i > jacobsthal_nums[jacobsthal_idx - 1]; i--) {
			// std::cout << "idx: " << i << "\n";
			idx = searchSetIdx(main, sub[i - 1].second);
			idx = binarySearch(main, idx, sub[i - 1].first);
			main.insert(main.begin() + idx, 1, sub[i - 1]);
		}

		jacobsthal_idx++;
	}

	if (last.first != -1) {
		idx = binarySearch(main, main.size(), last.first);
		main.insert(main.begin() + idx, 1, last);
	}
}

template<class container>
int PmergeMe<container>::searchSetIdx(pii& main, int idx) {
	for (unsigned int i = idx; i < main.size(); i++)
		if (idx == main[i].second)
			return i;
	return -1;
}

template<class container>
int PmergeMe<container>::binarySearch(pii& main, int idx, int values) {
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

template<class container>
void PmergeMe<container>::printBeforeNums(void) const {
	std::cout << "Before:\t";
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << "\n";
}

template<class container>
void PmergeMe<container>::printAfterNums(pii& main) const {
	std::cout << "After:\t";
	for (unsigned int i = 0; i < main.size(); i++)
		std::cout << main[i].first << " ";
	std::cout << "\n";
}

template<class container>
void PmergeMe<container>::calJacobsthal(void) {
	int	i = 2;
	while (true) {
		jacobsthal_nums.push_back(jacobsthal_nums[i - 1] + 2 * jacobsthal_nums[i - 2]);
		if (jacobsthal_nums[i] >= half_size)
			break;
		i++;
	}

	// std::cout << "print jacobsthal nums: ";
	// for (unsigned int i = 2; i < jacobsthal_nums.size(); i++)
	// 	std::cout << jacobsthal_nums[i] << " ";
	// std::cout << "\n\n";
}

template<class container>
void PmergeMe<container>::setStartTime(void) {
	start = clock();
	// 마이크로초 == 1/1,000,000
	// clock 함수는 프로그램 실행 시작부터 함수 호출 시점까지 경과한 CPU 시간이고, 마이크로초 단위
}

template<class container>
void PmergeMe<container>::printTime(std::string type) {
	clock_t total = clock() - start;

	std::cout << "Time to process a range of " << nums.size()	\
				<< " elements with std::" << type << " : " << total << " us\n";
}

template<class container>
void PmergeMe<container>::printPairs(std::string str, std::string type, pii pairs) {
	std::cout << "\n" << str << "\n";
	std::cout << type << "\n";
	for (unsigned int i = 0; i < pairs.size(); i++)
		std::cout << " < " << pairs[i].first << ", " << pairs[i].second << " >\n";
	std::cout << "\n";
}
