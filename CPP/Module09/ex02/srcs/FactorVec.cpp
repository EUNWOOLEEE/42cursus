#include "../incs/FactorVec.hpp"

FactorVec::FactorVec(void) {}

FactorVec::FactorVec(int _num) : num(_num) {}

FactorVec::~FactorVec(void) {}

FactorVec::FactorVec(const FactorVec& obj) : num(obj.num), idx(obj.idx) {}

FactorVec& FactorVec::operator= (const FactorVec& obj) {
	if (this != &obj) {
		num = obj.num;
		idx = obj.idx;
	}
	return *this;
}

void FactorVec::print(void) {
	std::cout << "[ " << num << " ] ";
	for (unsigned int i = 0; i < idx.size(); i++)
		std::cout << idx[i] << " ";
	std::cout << "\n";
}