#include "../incs/MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "Test: MutantStack\n\n";

	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top of stack: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << "\n\nTest: List\n\n";

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	
	std::cout << "Back of list: " << list.back() << std::endl;
	
	list.pop_back();
	
	std::cout << "Size of list: " << list.size() << std::endl;
	
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> l(list);
	return 0;
}