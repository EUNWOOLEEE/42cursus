#ifndef PLIST_H
# define PLIST_H

# include <list>
# include <stack>

# include "PmergeMe.hpp"

template<class container>
class Plist : PmergeMe<container = std::list> {
	public:
		Plist(void);
		~Plist(void);

	private:
		Plist(void);
		Plist(const Plist& obj);

		Plist& operator= (const Plist& obj);
};

#endif