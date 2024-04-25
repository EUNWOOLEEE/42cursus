#ifndef PDEQUE_H
# define PDEQUE_H

# include <deque>

# include "PmergeMe.hpp"

class Pdeque : PmergeMe< std::deque<int> > {
	public:
		Pdeque(void);
		~Pdeque(void);

	private:
		Pdeque(void);
		Pdeque(const Pdeque& obj);

		Pdeque& operator= (const Pdeque& obj);
};

#endif