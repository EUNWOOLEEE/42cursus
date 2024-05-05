#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <exception>
# include <ctime>

# include "FactorVec.hpp"
# include "FactorDeq.hpp"

typedef std::vector<FactorVec>	vec_fv;
typedef std::deque<FactorDeq>	deq_fd;

class PmergeMe {
	public:
		PmergeMe(void);
		~PmergeMe(void);

		/* VECTOR */
		void	runVec(int _num_cnt, char** _nums);
		void	initVec(char** _nums, vec_fv& nums) const;
		void	sortVec(vec_fv& nums, int size, int depth) const;
		void	divideVec(vec_fv& nums, vec_fv& main, vec_fv& sub, int chain_size) const;
		void	insertVec(vec_fv& main, vec_fv& sub, int chain_size, int depth) const;
		void	insertLastVec(vec_fv& main, FactorVec& last, int size) const;
		vec_i	getIndexesVec(vec_fv& main, int chain_size, int depth) const;
		int		findPosVec(vec_fv& main, int target, unsigned int depth) const;
		int		binarySearchVec(vec_fv& main, int pos, int target) const;
		void	printAfterVec(vec_fv& nums) const;

		/* DEQUE */
		void	runDeq(int _num_cnt, char** _nums);
		void	initDeq(char** _nums, deq_fd& nums) const;
		void	sortDeq(deq_fd& nums, int size, int depth) const;
		void	divideDeq(deq_fd& nums, deq_fd& main, deq_fd& sub, int chain_size) const;
		void	insertDeq(deq_fd& main, deq_fd& sub, int chain_size, int depth) const;
		void	insertLastDeq(deq_fd& main, FactorDeq& last, int size) const;
		deq_i	getIndexesDeq(deq_fd& main, int chain_size, int depth) const;
		int		findPosDeq(deq_fd& main, int target, unsigned int depth) const;
		int		binarySearchDeq(deq_fd& main, int pos, int target) const;
		void	printAfterDeq(deq_fd& nums) const;

		/* COMMON */
		void	printBefore(char** nums) const;
		int		convertNum(char* num_str) const;
		int		calJacobsthal(int n) const;
		void	printTime(std::string type) const;

	private:
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		clock_t	start;
		int		num_cnt;
};

#endif