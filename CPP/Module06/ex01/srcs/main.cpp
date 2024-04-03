#include <new>
#include <ios>

#include "Data.hpp"
#include "Serializer.hpp"

void	printAddress( void *ptr );
void	printAddressUint( uintptr_t ptr );

int main( void )
{
	Data	*origin = new Data("hello");
	std::cout << "\n";

	std::cout << "[ origin data ]\n";
	std::cout << "    name: " << origin->getName() << "\n";
	std::cout << "    addr: " << origin << "\n";
	std::cout << "    raw bits: ";
	printAddress(origin);
	std::cout << "\n";

	std::cout << "---------------- Test: try serialize ----------------\n\n";
	uintptr_t	serialized = Serializer::serialize(origin);
	Data		*deserialized = Serializer::deserialize(serialized);

	std::cout << "[ serialized data ]\n";
	std::cout << "    addr: " << serialized << "\n";
	std::cout << "    raw bits: ";
	printAddressUint(serialized);
	std::cout << "\n";

	std::cout << "[ deserialized data ]\n";
	std::cout << "    name: " << deserialized->getName() << "\n";
	std::cout << "    addr: " << deserialized << "\n";
	std::cout << "    raw bits: ";
	printAddress(deserialized);
	std::cout << "\n";

	delete(origin);
}

void printAddress( void *ptr )
{
	size_t size = sizeof(ptr);

    const unsigned char *bytes = reinterpret_cast<const unsigned char *>(&ptr);
    for (size_t idx = 0; idx < size; ++idx)
	{
        for (int bit = 7; bit >= 0; --bit)
		{
            int raw = (bytes[idx] >> bit) & 01;
            std::cout << raw;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void printAddressUint( uintptr_t ptr )
{
	for (size_t len = sizeof(ptr) * 8; len > 0; --len)
	{
		std::cout << (ptr >> (len - 1) & 01);
		if ((len - 1) % 8 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}

