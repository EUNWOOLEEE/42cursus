#ifndef FACTORVEC_HPP
# define FACTORVEC_HPP

# include <iostream>
# include <vector>

typedef std::vector<int>	vec_i;

class FactorVec {
	public:
		FactorVec(void);
		FactorVec(int _num);
		~FactorVec(void);
		FactorVec(const FactorVec& obj);

		FactorVec& operator= (const FactorVec& obj);

		void	print(void);

		int		num;
		vec_i	idx;
};

#endif