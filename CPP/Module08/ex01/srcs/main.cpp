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
		

		// std::cout << "Test: try add overlaped num\n\n";
		// sp.addNumber(5);


		// std::cout << "\n\nTest: try add exceeded num\n\n";
		// sp.addNumber(25);
		// sp.addNumber(35);


		/*-----------------------------------------------*/


		// std::cout << "Test: try fill 10000\n\n";
		// Span				sp(15000);
		// std::vector<int>	tmp;

		// for (int i = 0; i < 15000; i++)
		// 	tmp.push_back(i);

		// // like insert
		// sp.fillNumbers(tmp.begin(), tmp.end(), tmp.size());
		// std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		// std::cout << "arr current size: " << sp.getCurSize() << "\n";
		// std::cout << "idx[0]: " << sp[0] << "\n";
		// std::cout << "idx[5000]: " << sp[5000] << "\n";
		// std::cout << "idx[10000]: " << sp[10000] << "\n";


		// std::cout << "\n\nTest: out of range\n\n";
		// std::cout << sp[15000] << "\n";


		/*-----------------------------------------------*/


		// std::cout << "Test: try fill after add\n\n";
		// Span				sp(11);
		// std::vector<int>	tmp;

		// for (int i = 0; i < 10; i++)
		// 	tmp.push_back(i);

		// sp.addNumber(5);
		// sp.fillNumbers(tmp.begin(), tmp.end(), tmp.size());

		// std::cout << "arr capacity size: " << sp.getMaxSize() << "\n";
		// std::cout << "arr current size: " << sp.getCurSize() << "\n";
		// sp.printNums();

		// std::cout << "\n\nTest: try fill over size\n\n";
		// sp.fillNumbers(tmp.begin(), tmp.end(), tmp.size());

	
	} catch (const std::invalid_argument& e) {
		std::cout << e.what() << "\n";
	} catch (const std::out_of_range& e) {
		std::cout << e.what() << "\n";
	}

	return 0;
}