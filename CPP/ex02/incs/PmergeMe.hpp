#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <exception>
# include <ctime>

template<class container>
class PmergeMe {
	public:
		typedef	container< std::pair<int, int> >	pii;

		PmergeMe(int _num_cnt, char** _nums);
		~PmergeMe(void);

		void	sort(int argc, char** argv);
		pii		init(void);
		void	divide(pii& main, pii& sub, pii& tmp);
		void	insert(pii& main, pii& sub);
		int		searchSetIdx(pii& main, int idx);
		int		binarySearch(pii& main, int idx, int values);
		void	printBeforeNums(void) const;
		void	printAfterNums(pii& main) const;

		void	checkDigits(char* num_str) const;
		void	calJacobsthal(void);
		void	setStartTime(void);
		void	printTime(std::string type);

		void	printPairs(std::string str, std::string type, pii pairs);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		clock_t				start;
		size_t				num_cnt;
		container<int>		nums;
		std::pair<int, int>	last;
		unsigned int		chain_size;
		container<int>		jacobsthal_nums;
};

#endif