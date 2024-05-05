#ifndef FACTORDEQ_HPP
# define FACTORDEQ_HPP

# include <iostream>
# include <deque>

typedef std::deque<int>	deq_i;

class FactorDeq {
	public:
		FactorDeq(void);
		FactorDeq(int _num);
		~FactorDeq(void);
		FactorDeq(const FactorDeq& obj);

		FactorDeq& operator= (const FactorDeq& obj);

		void	print(void);

		int		num;
		deq_i	idx;
};

#endif