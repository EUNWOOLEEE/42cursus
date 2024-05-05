#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <exception>
# include <ctime>
# include <deque>

# include "FactorVec.hpp"

typedef std::vector<FactorVec>	vec_fv;

class PmergeMe {
	public:
		PmergeMe(void);
		~PmergeMe(void);

		void	runVec(int num_cnt, char** _nums);
		void	initVec(int num_cnt, char** _nums, vec_fv& nums);
		void	sortVec(vec_fv& nums, int size, int depth);
		void	divideVec(vec_fv& nums, vec_fv& main, vec_fv& sub, int chain_size);
		void	insertVec(vec_fv& main, vec_fv& sub, int chain_size, int depth);
		vec_i	getIndexesVec(vec_fv& main, int chain_size, int depth);
		int		binarySearchVec(vec_fv& main, int pos, int target);
		void	printBeforeVec(int num_cnt, char** nums) const;
		void	printAfterVec(vec_fv& nums) const;

		// common
		int		calJacobsthal(int n);
		int		convertNum(char* num_str) const;
		void	printTime(clock_t start, int num_cnt);

	private:
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);
};

#endif