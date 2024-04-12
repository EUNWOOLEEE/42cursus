#include "../incs/iter.hpp"

template <typename T>
void print(T& tmp) {
	std::cout << tmp << " ";
}

int main() {
	std::cout << "Test: integer array\n";
	int	int_arr[5] = {1, 2, 3, 4, 5};
	::iter(arr_ptr, 5, ::print);
	std::cout << "\n\n";


	std::cout << "Test: char array\n";
	char char_arr[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
	::iter(char_arr, 5, ::print);
	std::cout << "\n\n";


	std::cout << "Test: double array\n";
	double double_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(double_arr, 5, ::print);
	std::cout << "\n";

	return 0;
}