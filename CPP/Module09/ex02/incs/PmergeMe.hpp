#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <sys/time.h>
# include <iomanip>

typedef	std::vector< std::pair<int, int> >	vpi;
typedef	std::list< std::pair<int, int> >	lpi;

class PmergeMe {
	public:
		PmergeMe(int _num_count, char** _nums);
		~PmergeMe(void);

		void	sortVector(void);
		vpi		initVector(void);
		void	divideVector(vpi& main, vpi& sub, vpi& tmp);
		void	insertVector(vpi& main, vpi& sub);
		int		searchSetIdxVector(vpi& main, int idx);
		int		binarySearchVector(vpi& main, int idx, int values);
		void	printBeforeNumsVector(void) const;
		void	printAfterNumsVector(vpi& main) const;

		void	calJacobsthal(void);
		void	setStartTime(void);
		void	printTime(std::string type);

		void	printVectorPairs(std::string str, std::string type, vpi pairs);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		size_t						num_count;
		std::vector<int>			nums;
		std::pair<int, int>			last;
		unsigned int				half_size;
		std::vector<unsigned int>	jacobsthal_nums;
		clock_t						start;
};

#endif