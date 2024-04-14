#ifndef MutantStack_H
# define MutantStack_H

# include <iostream>
# include <exception>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack& obj);

		MutantStack& operator= (const MutantStack& obj);

		class iterator {
			public:
			private:
		}

		void			push(const T& value);
		void			pop(void);
		const T&		top(void) const;
		unsigned int	size(void) const;
		// T*				begin(void);
		// T*				end(void);

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

// template <typename T>
// T* MutantStack<T>::begin(void) { mstack.top }

// template <typename T>
// T* MutantStack<T>::end(void) {}

#endif