#ifndef SERVERBLOCK_HPP
# define SERVERBLOCK_HPP

# include <list>
# include <iostream>

# include "location.hpp"

class ServerBlock {
	public:
		ServerBlock(void);
		ServerBlock(const ServerBlock& obj);
		~ServerBlock(void);

		ServerBlock& operator =(const ServerBlock& src);

		void						setPort(size_t _port);
		void						setDomain(std::string _domain);

		size_t						getPort(void) const;
		const std::string&			getDomain(void) const;
		std::list<Location>&		getLocationList(void);
		const std::list<Location>&	getLocationListConst(void) const;

	private:
		size_t				port;
		std::string			domain;

		std::list<Location> location_list;
};

#endif