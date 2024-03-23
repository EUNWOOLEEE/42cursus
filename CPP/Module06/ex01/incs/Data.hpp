#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	public:
		Data(std::string _name);
		Data(const Data& obj);
		~Data(void);

		Data& operator =(const Data& obj);

	private:
		Data(void);

		std::string	name;
};

#endif