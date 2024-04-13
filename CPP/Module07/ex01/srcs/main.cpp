#include "../incs/iter.hpp"

int main() {
	std::cout << "Test: integer array\n";
	int	int_arr[5] = {1, 2, 3, 4, 5};
	::iter(int_arr, 5, ::print);
	::iter(int_arr, 5, ::changeValue);
	std::cout << "\n";
	::iter(int_arr, 5, ::print);
	std::cout << "\n\n";


	std::cout << "Test: char array\n";
	char char_arr[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
	::iter(char_arr, 5, ::print);
	::iter(char_arr, 5, ::changeValue);
	std::cout << "\n";
	::iter(char_arr, 5, ::print);
	std::cout << "\n\n";


	std::cout << "Test: double array\n";
	double double_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(double_arr, 5, ::print);
	::iter(double_arr, 5, ::changeValue);
	std::cout << "\n";
	::iter(double_arr, 5, ::print);
	std::cout << "\n";

	return 0;
}