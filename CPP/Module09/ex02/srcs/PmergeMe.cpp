#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(int _num_count, char** _nums) : num_count(_num_count), nums(_num_count), last(std::make_pair(-1, 0)) {
	std::cout << "[OCCF] PmergeMe constructor called\n";

	for (size_t i = 0; i < num_count; i++) //숫자 아닌거나 음수 예외처리
		nums[i] = atoi(_nums[i]);

	jacobsthal_nums.push_back(0);
	jacobsthal_nums.push_back(1);
}

PmergeMe::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

void PmergeMe::sortVector(void) {
	setStartTime();
	printBeforeNumsVector();

	vpi	tmp_pairs = initVector();
	std::sort(tmp_pairs.begin(), tmp_pairs.end());

	// printVectorPairs("Step2: Sort by larger", "main, sub", tmp_pairs);

	vpi	main(half_size);
	vpi	sub(half_size);

	divideVector(main, sub, tmp_pairs);
	calJacobsthal();

	// std::cout << "Step3: divide main and sub";
	// printVectorPairs("", "main, index", main);
	// printVectorPairs("", "sub, index", sub);

	insertVector(main, sub);

	printAfterNumsVector(main);
	printTime("vector");

	// printVectorPairs("Step4: Sort", "main, index", main);
}

vpi PmergeMe::initVector(void) {
	if (num_count % 2)
		last.first = *(nums.rbegin());
	
	half_size = nums.size()/ 2;
	vpi	tmp_pairs(half_size);

	for (unsigned int i = 0, j = half_size; i < half_size; i++, j++) {
		int	first = nums[i] > nums[j] ? nums[i] : nums[j];
		int second = nums[i] < nums[j] ? nums[i] : nums[j];

		tmp_pairs[i] = std::make_pair(first, second);
	}
	return tmp_pairs;
}

void PmergeMe::divideVector(vpi& main, vpi& sub, vpi& tmp) {
	for (unsigned int i = 0; i < half_size; i++) {
		main[i] = std::make_pair(tmp[i].first, i);
		sub[i] = std::make_pair(tmp[i].second, i);
	}
}

void PmergeMe::insertVector(vpi& main, vpi& sub) {
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
			idx = searchSetIdxVector(main, sub[i - 1].second);
			idx = binarySearchVector(main, idx, sub[i - 1].first);
			main.insert(main.begin() + idx, 1, sub[i - 1]);
		}

		jacobsthal_idx++;
	}

	if (last.first != -1) {
		idx = binarySearchVector(main, main.size(), last.first);
		main.insert(main.begin() + idx, 1, last);
	}
}

int PmergeMe::searchSetIdxVector(vpi& main, int idx) {
	for (unsigned int i = idx; i < main.size(); i++)
		if (idx == main[i].second)
			return i;
	return -1;
}

int PmergeMe::binarySearchVector(vpi& main, int idx, int values) {
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

void PmergeMe::printBeforeNumsVector(void) const {
	std::cout << "Before:\t";
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << "\n";
}

void PmergeMe::printAfterNumsVector(vpi& main) const {
	std::cout << "After:\t";
	for (unsigned int i = 0; i < main.size(); i++)
		std::cout << main[i].first << " ";
	std::cout << "\n";
}

void PmergeMe::calJacobsthal(void) {
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

void PmergeMe::setStartTime(void) {
	start = clock();
	// 마이크로초 == 1/1,000,000
	// clock 함수는 프로그램 실행 시작부터 함수 호출 시점까지 경과한 CPU 시간이고, 마이크로초 단위
}

void PmergeMe::printTime(std::string type) {
	clock_t total = clock() - start;

	std::cout << "Time to process a range of " << nums.size()	\
				<< " elements with std::" << type << " : " << total << " us\n";
}

void PmergeMe::printVectorPairs(std::string str, std::string type, vpi pairs) {
	std::cout << "\n" << str << "\n";
	std::cout << type << "\n";
	for (unsigned int i = 0; i < pairs.size(); i++)
		std::cout << " < " << pairs[i].first << ", " << pairs[i].second << " >\n";
	std::cout << "\n";
}
