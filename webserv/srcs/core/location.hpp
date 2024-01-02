#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <iostream>

class Location {
	public:
		Location(std::string _block_path);
		Location(const Location& obj);
		~Location(void);

		Location& operator =(const Location& src);

		void setStaticPath(std::string _block_path);

		const std::string& getBlockPath(void) const;
		const std::string& getStaticPath(void) const;

	private:
		Location(void);

		std::string	block_path;
		std::string	static_path;
		// CGI
};

#endif