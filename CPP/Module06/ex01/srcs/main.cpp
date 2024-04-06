#include "Data.hpp"
#include "Serializer.hpp"

// void	printAddress( void *ptr );
// void	printAddressUint( uintptr_t ptr );

int main( void )
{
	Data	*origin = new Data("hello", 54321);
	std::cout << "\n";

	std::cout << "[ origin data ]\n";
	std::cout << "    str: " << origin->getStr() << "\n";
	std::cout << "    n: " << origin->getN() << "\n";
	std::cout << "    addr: " << origin << "\n";
	std::cout << "\n";

	std::cout << "---------------- Test: try serialize ----------------\n\n";
	uintptr_t	serialized = Serializer::serialize(origin);
	Data		*deserialized = Serializer::deserialize(serialized);

	std::cout << "[ serialized data ]\n";
	std::cout << "    addr(hex): " << std::hex << serialized << "\n";
	std::cout << "    addr(dec): " << std::dec << serialized << "\n";
	std::cout << "\n";

	std::cout << "[ deserialized data ]\n";
	std::cout << "    str: " << deserialized->getStr() << "\n";
	std::cout << "    n: " << deserialized->getN() << "\n";
	std::cout << "    addr: " << deserialized << "\n";
	std::cout << "\n";

	delete(origin);
}
