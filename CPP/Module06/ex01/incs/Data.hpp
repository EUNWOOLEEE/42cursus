#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	public:
		Data(std::string _str, int _n);
		Data(const Data& obj);
		~Data(void);

		Data& operator =(const Data& obj);

		std::string&	getStr(void);
		int				getN(void);

	private:
		Data(void);

		std::string	str;
		int			n;
};

#endif
