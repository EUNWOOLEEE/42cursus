#include "../incs/Array.hpp"

int main() {
	std::cout << "Test: empty array of int\n\n";
	Array<int> int_arr;
	std::cout << "int_arr size: " << int_arr.size() << "\n";
	try {
		std::cout << int_arr[0] << "\n";
	} catch ( const Array<int>::outOfRangeException& e ) {
		std::cout << e.what() << "\n";
	}


	// std::cout << "Test: array of int, out of range\n\n";
	// Array<int> int_arr(5);

	// int n = 1;
	// for (unsigned int i = 0; i < int_arr.size(); i++)
	// 	int_arr[i] = n++;

	// std::cout << "int_arr size: " << int_arr.size() << "\n";
	// try {
	// 	for (unsigned int i = 0; i <= int_arr.size(); i++)
	// 		std::cout << int_arr[i] << "\n";
	// } catch ( const Array<int>::outOfRangeException& e ) {
	// 	std::cout << e.what() << "\n";
	// }


	// std::cout << "Test: array of string, out of range\n\n";
	// Array<std::string> str_arr(5);

	// std::string tmp("hello");
	// for (unsigned int i = 0; i < str_arr.size(); i++)
	// 	str_arr[i] = tmp.substr(0, i + 1);

	// std::cout << "str_arr size: " << str_arr.size() << "\n";
	// try {
	// 	for (unsigned int i = 0; i <= str_arr.size(); i++)
	// 		std::cout << str_arr[i] << "\n";
	// } catch ( const Array<std::string>::outOfRangeException& e ) {
	// 	std::cout << e.what() << "\n";
	// }


	// std::cout << "Test: const array of double\n\n";
	// const Array<double> double_arr(5);

	// int n = 1;
	// for (unsigned int i = 0; i < double_arr.size(); i++)
	// 	double_arr[i] = n++;

	// std::cout << "double_arr size: " << double_arr.size() << "\n";
	// try {
	// 	for (unsigned int i = 0; i < double_arr.size(); i++)
	// 		std::cout << double_arr[i] << "\n";
	// } catch ( const Array<double>::outOfRangeException& e ) {
	// 	std::cout << e.what() << "\n";
	// }


	return 0;
}