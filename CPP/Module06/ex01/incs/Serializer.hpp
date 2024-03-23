#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer {
	public:
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
	private:
		Serializer(void);
};

#endif