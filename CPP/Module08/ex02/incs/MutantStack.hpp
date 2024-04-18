#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack& obj);

		MutantStack& operator= (const MutantStack& obj);

		iterator		begin(void);
		const_iterator	begin(void) const;
		iterator		end(void);
		const_iterator	end(void) const;
};

template <typename T>
MutantStack<T>::MutantStack(void) {
	std::cout << "[OCCF] MutantStack default constructor called\n";
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
	std::cout << "[OCCF] MutantStack destructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) {
	std::cout << "[OCCF] MutantStack copy constructor called\n";

	this->c = obj.c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator= (const MutantStack& obj) {
	std::cout << "[OCCF] MutantStack copy assignment operator called\n";

	if (this != &obj)
		this->c = obj.c;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const { return this->c.end(); }

#endif