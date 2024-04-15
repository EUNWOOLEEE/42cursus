#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end())
		throw std::out_of_range("Target not found in container");
	return iter;
}

#endif