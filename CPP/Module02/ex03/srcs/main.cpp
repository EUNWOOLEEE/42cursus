#include "../incs/Fixed.hpp"
#include "../incs/Point.hpp"

int main( void ) {
	Point a(2.5, 5), b(5, 0), c(0, 0), p(1, 1);

	std::cout << bsp(a, b, c, p) << std::endl;
	return 0;
}