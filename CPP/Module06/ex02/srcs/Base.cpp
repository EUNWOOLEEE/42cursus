#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <ctime>
#include <cstdlib>
#include <stdexcept>

Base::~Base(void) {}

// 업캐스팅 : 기본 클래스 포인터가 파생 클래스 객체를 가리킴
Base* generate(void){
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int	random = std::rand() % 3;

	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

// 다운캐스팅 : 동일한 타입의 포인터가 동일한 타입의 객체를 가리킴
void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "(Pointer) Object type is [A]\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "(Pointer) Object type is [B]\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "(Pointer) Object type is [C]\n";
}

void identify(Base& p){
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "(Reference) Object type is [A]\n";
	} catch (const std::bad_cast& e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "(Reference) Object type is [B]\n";
	} catch (const std::bad_cast& e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "(Reference) Object type is [C]\n";
	} catch (const std::bad_cast& e) {}
}
