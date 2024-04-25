#ifndef PVECTOR_H
# define PVECTOR_H

# include <vector>
# include <stack>

# include "PmergeMe.hpp"

template<class container>
class Pvector : PmergeMe<container = std::vector> {
	public:
		Pvector(void);
		~Pvector(void);

	private:
		Pvector(void);
		Pvector(const Pvector& obj);

		Pvector& operator= (const Pvector& obj);

};

#endif