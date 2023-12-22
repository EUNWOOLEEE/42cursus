#ifndef CONF_HPP
# define CONF_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include "cmd.hpp"

# define CONF_MAIN		0x00000100
# define CONF_SRV		0x00000200
# define CONF_LOC		0x00000400

class Conf {
	public:
		Conf(void);
		Conf(std::string _file_name);
		Conf(const Conf& src);
		~Conf(void);

		Conf&	operator =(const Conf& src);

		int						setFile(std::string _file_name);
		int						setCmd(void);

		std::ifstream&			getFile(void);
		const std::ifstream&	getFileConst(void) const;
		const Cmd*				getCmdListConst(int loc_type) const;
		int						getCmdMaxConst(int loc_type) const;

	private:

		std::ifstream		file;
		std::string			file_name;

		Cmd					*main_cmd;
		Cmd					*srv_cmd;
		Cmd					*loc_cmd;
		static const int	main_cmd_max;
		static const int	srv_cmd_max;
		static const int	loc_cmd_max;
};

int parseConf(Cycle &cycle, Conf &conf);

int mainWorkerProcesses(Cycle& cycle, std::string tokens[]);
int mainWorkerConnections(Cycle& cycle, std::string tokens[]);
int mainClientMaxBodySize(Cycle& cycle, std::string tokens[]);
int serverListen(Cycle& cycle, std::string tokens[]);
int serverName(Cycle& cycle, std::string tokens[]);
int serverErrorPage(Cycle& cycle, std::string tokens[]);

#endif