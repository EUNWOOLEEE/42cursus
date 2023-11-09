#include "../incs/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 10.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	const Fixed c(20.1016f);
	std::cout << (b != c) << std::endl;
	std::cout << (b <= c) << std::endl;

	const Fixed d( Fixed( 22.25f ) / Fixed( 2 ));
	std::cout << d << std::endl;

	std::cout << Fixed::min( c, d ) << std::endl;

	Fixed e( 0 ), f( 0 );
	std::cout << Fixed::max( ++e, f ) << std::endl;
	std::cout << (e > f) << std::endl;
	

	return 0;
}