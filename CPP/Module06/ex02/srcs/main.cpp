#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

int main() {
	std::cout << "----------- Test: A -----------\n";
	A* a = new A;
	identify(a);
	identify(*a);
	delete a;
	std::cout << "\n\n";

	std::cout << "----------- Test: B -----------\n";
	B* b = new B;
	identify(b);
	identify(*b);
	delete b;
	std::cout << "\n\n";

	std::cout << "----------- Test: C -----------\n";
	C* c = new C;
	identify(c);
	identify(*c);
	delete c;
	std::cout << "\n\n";

	// std::cout << "----------- Test: random -----------\n";
	// Base* base = generate();
	// identify(base);
	// identify(*base);
	// delete base;
	
	std::cout << "----------- Test: Bad cast -----------\n";
	Base* base = new Base;
	identify(base);
	identify(*base);
	delete base;
	std::cout << "\n\n";

	return 0;
}
