#ifndef LOCATIONBLOCK_HPP
# define LOCATIONBLOCK_HPP

# include <vector>
# include <iostream>

# define METHOD_GET		0x00000001
# define METHOD_POST	0x00000010
# define METHOD_DELETE	0x00000100

class LocationBlock {
	public:
		LocationBlock(std::string _location_path);
		LocationBlock(const LocationBlock& obj);
		~LocationBlock(void);

		LocationBlock& operator =(const LocationBlock& src);

		void 						setSubRoot(std::string _location_path);
		void 						setAllowedMethod(int _allowed_method);
		void 						setAutoIndex(int _autoindex);

		const std::string&			getLocationPath(void) const;
		const std::string&			getSubRoot(void) const;
		int							getAllowedMethod(void) const;
		int							getAutoIndex(void) const;
		std::vector<std::string>&	getIndex(void);

	private:
		std::string					location_path;
		std::string					sub_root;
		int							allowed_method;
		int							autoindex;
		std::vector<std::string>	index;
};

#endif