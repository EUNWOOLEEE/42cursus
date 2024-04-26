#ifndef MYLIST_HPP
# define MYLIST_HPP

# include <iostream>
# include <list>
# include <exception>

class Mylist : public std::list<std::string> {
	public:
		Mylist(void);
		~Mylist(void);
		Mylist(const Mylist& obj);

		Mylist& operator= (const Mylist& obj);

		std::string& operator[] (unsigned int idx);
		const std::string& operator[] (unsigned int idx) const;
};

#endif