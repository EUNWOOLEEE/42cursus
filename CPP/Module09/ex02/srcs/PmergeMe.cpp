#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(void) : start(clock()) {
	std::cout << "[OCCF] PmergeMe constructor called\n";
}

PmergeMe::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

void PmergeMe::runVec(int _num_cnt, char** _nums) {
	num_cnt = _num_cnt - 1;
	printBefore(&_nums[1]);

	vec_fv	nums(num_cnt);

	initVec(&_nums[1], nums);
	sortVec(nums, num_cnt, 0);
	
	printAfterVec(nums);
	printTime();
}

void PmergeMe::initVec(char** _nums, vec_fv& nums) {
	for (int i = 0; i < num_cnt; i++)
		nums[i] = FactorVec(convertNum(_nums[i]));
}

void PmergeMe::sortVec(vec_fv& nums, int size, int depth) {
	if (size == 1)
		return ;

	int		chain_size = size / 2;
	vec_fv	main(chain_size);
	vec_fv	sub(chain_size);

	divideVec(nums, main, sub, chain_size);
	
	sortVec(main, chain_size, depth + 1);
	insertVec(main, sub, chain_size, depth);
	insertLastVec(main, nums[size - 1], size);

	for (int i = 0; i < size; i++)
		nums[i] = main[i];
}

void PmergeMe::divideVec(vec_fv& nums, vec_fv& main, vec_fv& sub, int chain_size) {
	for (int i = 0; i < chain_size; i++) {
		main[i] = nums[i];
		sub[i] = nums[i + chain_size];

		if (main[i].num < sub[i].num)
			std::swap(main[i], sub[i]);

		main[i].idx.push_back(i);
	}
}

void PmergeMe::insertVec(vec_fv& main, vec_fv& sub, int chain_size, int depth) {
	int		j = 1;
	int		j_cnt = 3;
	int		pre_j, pair_idx, pos;
	vec_i	indexes = getIndexesVec(main, chain_size, depth);

	main.insert(main.begin(), 1, sub[indexes[0]]);

	while (true) {
		pre_j = j;
		j = calJacobsthal(j_cnt);
		if (j > chain_size)
			j = chain_size;

		for (int i = j; i > pre_j; i--) {
			pair_idx = indexes[i - 1];
			pos = findPosVec(main, pair_idx, depth);
			pos = binarySearchVec(main, pos, sub[pair_idx].num);
			main.insert(main.begin() + pos, 1, sub[pair_idx]);
		}

		if (j == chain_size)
			break;

		j_cnt++;
	}
}

void PmergeMe::insertLastVec(vec_fv& main, FactorVec& last, int size) {
	if (size % 2) {
		int pos = binarySearchVec(main, main.size() - 1, last.num);
		main.insert(main.begin() + pos, 1, last);
	}
}

vec_i PmergeMe::getIndexesVec(vec_fv& main, int chain_size, int depth) {
	vec_i	indexes(chain_size);

	for (int i = 0; i < chain_size; i++)
		indexes[i] = main[i].idx[depth];

	return indexes;
}

int PmergeMe::findPosVec(vec_fv& main, int target, unsigned int depth) {
	for (unsigned int i = 0; i < main.size(); i++) {
		if (main[i].idx.size() >= depth + 1		\
			&& main[i].idx[depth] == target)
			return i;
	}
	return -1;
}

int PmergeMe::binarySearchVec(vec_fv& main, int pos, int target) {
	int	left = 0;
	int	mid;
	int	right = pos;

	while (left <= right) {
		mid = (left + right) / 2;

		if (main[mid].num > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

void PmergeMe::printAfterVec(vec_fv& nums) const {
	std::cout << "After: ";
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << nums[i].num << " ";
	std::cout << "\n";
}

// common
void PmergeMe::printBefore(char** nums) const {
	std::cout << "\nBefore: ";
	for (int i = 0; i < num_cnt; i++)
		std::cout << nums[i] << " ";
	std::cout << "\n";
}

int PmergeMe::convertNum(char* num_str) const {
	for (int i = 0; num_str[i]; i++)
		if (isdigit(num_str[i]) == false)
			throw std::runtime_error("Input values must be positive number");
	return atoi(num_str);
}

int PmergeMe::calJacobsthal(int n) {
	int	part1 = 0, second = 1, third = 1;

	if (n == 0)
		return part1;
	if (n == 1)
		return second;
	if (n == 2)
		return third;

	for (int i = 3; i <= n; i++) {
		part1 = second;
		second = third;
		third = second + 2 * part1;
	}
	return third;
}

void PmergeMe::printTime(void) {
	clock_t total = clock() - start;

	std::cout << "Time to process a range of " << num_cnt	\
				<< " elements with std::vector" << " : " << total << " us\n\n";
}
