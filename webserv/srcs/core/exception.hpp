#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <iostream>

class Exception{

	public:
		Exception(const std::string& msg);
		const char* what() const;

	private:
		std::string msg_;
};

#endif