#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(const T* arr, size_t len, void (*f)(const T&)) {
	if (arr == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len ; i++)
		f(arr[i]);
}

template <typename T>
void print(T& tmp) {
	std::cout << tmp << " ";
}

#endif