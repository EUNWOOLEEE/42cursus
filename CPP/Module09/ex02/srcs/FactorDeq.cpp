#include "../incs/FactorDeq.hpp"

FactorDeq::FactorDeq(void) {}

FactorDeq::FactorDeq(int _num) : num(_num) {}

FactorDeq::~FactorDeq(void) {}

FactorDeq::FactorDeq(const FactorDeq& obj) : num(obj.num), idx(obj.idx) {}

FactorDeq& FactorDeq::operator= (const FactorDeq& obj) {
	if (this != &obj) {
		num = obj.num;
		idx = obj.idx;
	}
	return *this;
}

void FactorDeq::print(void) {
	std::cout << "[ " << num << " ] ";
	for (unsigned int i = 0; i < idx.size(); i++)
		std::cout << idx[i] << " ";
	std::cout << "\n";
}