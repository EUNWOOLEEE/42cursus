#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <cmath>

typedef std::vector<int>::iterator iter;

class Span {
	public:
		Span(unsigned int N);
		~Span(void);
		Span(const Span& obj);

		Span&	operator= (const Span& obj);
		int		operator[] (unsigned int idx);
		int		operator[] (unsigned int idx) const;

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

		std::vector<int>	arr;
		unsigned int		max_size;
};

#endif