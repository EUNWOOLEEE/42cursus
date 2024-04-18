#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <cmath>

typedef std::vector<int>::iterator iter;

class RPN {
	public:
		RPN(unsigned int N);
		~RPN(void);
		RPN(const RPN& obj);

		RPN&	operator= (const RPN& obj);
		int		operator[] (unsigned int idx);
		int		operator[] (unsigned int idx) const;

		unsigned int	getMaxSize(void);

		void	addNumber(int n);
		void	fillNumbers(unsigned int len);
		int		shortestRPN(void);
		int		longestRPN(void);
		bool	checkOverlap(int n);
		void	printNums(void);

	private:
		RPN(void);

		std::vector<int>	arr;
		unsigned int		max_size;
};

#endif