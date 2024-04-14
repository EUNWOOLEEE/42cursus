#include "../incs/easyfind.hpp"

#include <vector>
#include <list>
#include <deque>

int	main(void) {
	std::cout << "Test: vector\n\n";
	try {
		std::vector<int> vec;

		for (int i = 0; i <= 10; i++)
			vec.push_back(i);

		std::vector<int>::iterator it = easyfind(vec, 10);
		std::cout << *it << "\n";

		it = easyfind(vec, 11);

	} catch (const std::out_of_range& e) {
		std::cout << e.what() << "\n";
	}


	// std::cout << "Test: list\n\n";
	// try {
	// 	std::list<int> lst;

	// 	for (int i = 0; i <= 10; i++)
	// 		lst.push_back(i);

	// 	std::list<int>::iterator it = easyfind(lst, 10);
	// 	std::cout << *it << "\n";

	// 	it = easyfind(lst, 11);
		
	// } catch (const std::out_of_range& e) {
	// 	std::cout << e.what() << "\n";
	// }


	// std::cout << "Test: deque<char>\n\n";
	// try {
	// 	std::deque<char> deq;

	// 	char c = 'a';
	// 	for (int i = 0; i < 5; i++)
	// 		deq.push_back(c++);

	// 	std::deque<char>::iterator it = easyfind(deq, 'c');
	// 	std::cout << *it << "\n";

	// 	it = easyfind(deq, 'f');
		
	// } catch (const std::out_of_range& e) {
	// 	std::cout << e.what() << "\n";
	// }

	return 0;
}