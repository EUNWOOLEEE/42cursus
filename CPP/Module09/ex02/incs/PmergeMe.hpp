#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class PmergeMe : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe& obj);

		PmergeMe& operator= (const PmergeMe& obj);

		iterator		begin(void);
		const_iterator	begin(void) const;
		iterator		end(void);
		const_iterator	end(void) const;
};


template <typename T>
PmergeMe<T>::PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe constructor called\n";
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {
	std::cout << "[OCCF] PmergeMe destructor called\n";
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& obj) {
	std::cout << "[OCCF] PmergeMe copy constructor called\n";

	if (this != &obj)
		this->c = obj.c;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator= (const PmergeMe& obj) {
	std::cout << "[OCCF] PmergeMe copy assignment operator called\n";

	if (this != &obj)
		this->c = obj.c;
	return *this;
}

template <typename T>
typename PmergeMe<T>::iterator PmergeMe<T>::begin(void) { return this->c.begin(); }

template <typename T>
typename PmergeMe<T>::const_iterator PmergeMe<T>::begin(void) const { return this->c.begin(); }

template <typename T>
typename PmergeMe<T>::iterator PmergeMe<T>::end(void) { return this->c.end(); }

template <typename T>
typename PmergeMe<T>::const_iterator PmergeMe<T>::end(void) const { return this->c.end(); }

#endif