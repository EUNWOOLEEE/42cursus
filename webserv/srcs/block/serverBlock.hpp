#ifndef SERVERBLOCK_HPP
# define SERVERBLOCK_HPP

# include <vector>
# include <iostream>

# include "locationBlock.hpp"

class ServerBlock {
	public:
		ServerBlock(void);
		ServerBlock(const ServerBlock& obj);
		~ServerBlock(void);

		ServerBlock& operator =(const ServerBlock& src);

		void								setPort(size_t _port);
		void								setDomain(std::string _domain);

		size_t								getPort(void) const;
		const std::string&					getDomain(void) const;
		std::vector<LocationBlock>&			getLocationBlocks(void);
		const std::vector<LocationBlock>&	getLocationBlocksConst(void) const;

	private:
		size_t						port;
		std::string					domain;

		std::vector<LocationBlock>	location_blocks;
};

#endif