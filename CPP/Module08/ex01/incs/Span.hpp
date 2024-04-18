#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <set>

typedef std::set<int>::iterator iter;

class Span {
	public:
		Span(unsigned int N);
		~Span(void);
		Span(const Span& obj);

		Span&	operator= (const Span& obj);

		unsigned int	getMaxSize(void);
		unsigned int	getCurSize(void);

		void	addNumber(int n);
		void	fillNumbers(iter begin, iter end, size_t len);
		int		shortestSpan(void);
		int		longestSpan(void);
		bool	checkOverlap(int n);
		void	printNums(void);

	private:
		Span(void);

		std::set<int>	nums;
		unsigned int	max_size;
};

#endif