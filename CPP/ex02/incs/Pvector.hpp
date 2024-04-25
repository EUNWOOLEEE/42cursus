#ifndef PVECTOR_H
# define PVECTOR_H

# include <vector>

# include "PmergeMe.hpp"

class Pvector : PmergeMe< std::vector<int> > {
	public:
		Pvector(int argc, char** argv);
		~Pvector(void);

	private:
		Pvector(void);
		Pvector(const Pvector& obj);

		Pvector& operator= (const Pvector& obj);

};

#endif