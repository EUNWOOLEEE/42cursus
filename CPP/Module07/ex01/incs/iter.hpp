#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* arr, size_t len, void (*f)(T&)) {
	for (int i = 0; i < len ; i++)
		f(arr[i]);
}

template <typename T>
void print(T& tmp) {
	std::cout << tmp << " ";
}

template <typename T>
void increase(T& tmp) {
	tmp++;
}

#endif