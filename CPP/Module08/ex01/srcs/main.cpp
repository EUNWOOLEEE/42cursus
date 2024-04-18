#include "../incs/Span.hpp"

int main()
{
	try {
		std::cout << "Test: subject test case\n\n";
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		std::cout << "arr current size: " << sp.getCurSize() << "\n";
		sp.printNums();

		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;


		/*-----------------------------------------------*/


		// Span sp = Span(3);

		// sp.addNumber(5);
		// sp.addNumber(15);

		// std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		// std::cout << "arr current size: " << sp.getCurSize() << "\n";
		// sp.printNums();
		
		// std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		// std::cout << "longest: " << sp.longestSpan() << std::endl;
		

		// std::cout << "Test: try add overlaped num\n\n";
		// sp.addNumber(5);


		// std::cout << "\n\nTest: try add exceeded num\n\n";
		// sp.addNumber(25);
		// sp.addNumber(35);


		/*-----------------------------------------------*/


		// std::cout << "Test: try fill 15000\n\n";
		// Span			sp(15000);
		// std::set<int>	tmp;

		// for (int i = 0; i < 15000; i++)
		// 	tmp.insert(i);

		// sp.fillNumbers(tmp.begin(), tmp.end(), tmp.size());
		// std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		// std::cout << "arr current size: " << sp.getCurSize() << "\n";
		// sp.printNums();


		/*-----------------------------------------------*/


		// std::cout << "Test: try fill after add\n\n";
		// Span			sp(11);
		// std::set<int>	tmp1;
		// std::set<int>	tmp2;

		// sp.addNumber(50);
		// sp.printNums();
		// std::cout << "\n";

		// for (int i = 0; i < 10; i++)
		// 	tmp1.insert(i);
		// sp.fillNumbers(tmp1.begin(), tmp1.end(), tmp1.size());

		// std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		// std::cout << "arr current size: " << sp.getCurSize() << "\n";
		// sp.printNums();

		// std::cout << "\n\nTest: try fill other nums\n\n";
		// for (int i = 100; i < 110; i++)
		// 	tmp2.insert(i);

		// sp.fillNumbers(tmp2.begin(), tmp2.end(), tmp2.size());
		// sp.printNums();

	
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << "\n";
	} catch (const std::out_of_range& e) {
		std::cout << e.what() << "\n";
	}

	return 0;
}