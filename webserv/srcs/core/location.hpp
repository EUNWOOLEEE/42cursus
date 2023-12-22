#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <iostream>

class Location {
	public:
		Location(void);
		Location(const Location& obj);
		~Location(void);

		Location& operator =(const Location& src);

	private:
		std::string	server_name;
		// CGI
};

#endif