#ifndef MutantStack_H
# define MutantStack_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <stack>
# include <deque>

		
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack& obj);

		MutantStack& operator= (const MutantStack& obj);

		typedef std::stack<T>::container_type::iterator iterator;

		void			push(const T& value);
		void			pop(void);
		const T&		top(void) const;
		unsigned int	size(void) const;
		typename iterator		begin(void);
		typename iterator		end(void);

	private:
		std::stack<T>	mstack;
};


template <typename T>
MutantStack<T>::MutantStack(void) {
	std::cout << "[OCCF] MutantStack constructor called\n";
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
	std::cout << "[OCCF] MutantStack destructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : mstack(obj.mstack) {
	std::cout << "[OCCF] MutantStack copy constructor called\n";
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator= (const MutantStack& obj) {
	std::cout << "[OCCF] MutantStack copy assignment operator called\n";

	if (this != &obj)
		mstack = obj.mstack;
	return *this;
}

template <typename T>
void MutantStack<T>::push(const T& value) { mstack.push(value); }

template <typename T>
void MutantStack<T>::pop(void) { mstack.pop(); }

template <typename T>
const T& MutantStack<T>::top(void) const { return mstack.top(); }

template <typename T>
unsigned int MutantStack<T>::size(void) const { return mstack.size(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) { mstack.c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) { mstack.c.end(); }

#endif