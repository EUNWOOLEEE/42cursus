#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

class PmergeMe {
	public:
		PmergeMe(int _num_count, char** _nums);
		~PmergeMe(void);

		void	rec();

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		size_t				num_count;
		std::vector<int>	nums;

};

#endif