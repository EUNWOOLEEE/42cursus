#ifndef CMD_HPP
# define CMD_HPP

# include <iostream>
# include "cycle.hpp"

enum cmd_args {
	CMD_NOARGS,
	CMD_TAKE1,
	CMD_TAKE2
};

typedef int (*handler_t)(Cycle&, std::string[]);

class Cmd {
	public:
		Cmd(void);
		Cmd(std::string _name, int _arg_cnt, handler_t _handler);
		Cmd(const Cmd& obj);
		~Cmd(void);

		Cmd& operator =(const Cmd& src);

		const std::string&	getName(void) const;
		int					getArgCnt(void) const;
		const handler_t&	getHandler(void) const;

	private:
		std::string	name;
		int			arg_cnt;
		handler_t	handler;
};

#endif