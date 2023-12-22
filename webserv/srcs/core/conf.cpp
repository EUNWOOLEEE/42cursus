#include "core.hpp"

const int Conf::main_cmd_max = 3;
const int Conf::srv_cmd_max = 3;
const int Conf::loc_cmd_max = 10;

static int parseMain(Cycle &cycle, const Cmd *cmd, int cmd_max, std::ifstream& file);
static int parseServer(Cycle &cycle, const Cmd *cmd, int cmd_max, std::ifstream& file);
static int checkConfLocation(std::string str[], int cur);
static int tokenizer(char *str, std::string *tokens);

Conf::Conf(void) {
	main_cmd = NULL;
	srv_cmd = NULL;
	loc_cmd = NULL;
}

Conf::Conf(std::string _file_name) {
	if (setFile(_file_name) == -1)
		throw Exception("Open configure file error!");
		
	if (setCmd() == -1)
		throw Exception("Set configure command error!");
}

Conf::Conf(const Conf& src) {
	*this = src;
}

Conf& Conf::operator =(const Conf& src) {
	if (this != &src) {
		file_name = src.file_name;
		file.close();
		file.open(file_name);
		if (file.is_open() == FALSE)
			throw Exception("File open error!");

		if (main_cmd)
			delete[](main_cmd);
		main_cmd = new Cmd[main_cmd_max]();
		for (int i = 0; i < main_cmd_max; i++)
			main_cmd[i] = src.main_cmd[i];

		if (srv_cmd)
			delete[](srv_cmd);
		srv_cmd = new Cmd[srv_cmd_max]();
		for (int i = 0; i < srv_cmd_max; i++)
			srv_cmd[i] = src.srv_cmd[i];

		if (loc_cmd)
			delete[](loc_cmd);
		loc_cmd = new Cmd[loc_cmd_max]();
		for (int i = 0; i < loc_cmd_max; i++)
			loc_cmd[i] = src.loc_cmd[i];
	}
	return (*this);
}

Conf::~Conf(void) {}

int Conf::setFile(std::string _file_name) {
	file_name = _file_name;
	file.open(file_name);
	if (file.is_open() == FALSE)
		return -1; //error
	return 0;
}

std::ifstream& Conf::getFile(void) {
	return file;
}

const std::ifstream& Conf::getFileConst(void) const {
	return file;
}

int Conf::setCmd(void) {
	main_cmd = new Cmd[main_cmd_max]();
	srv_cmd = new Cmd[srv_cmd_max]();
	loc_cmd = new Cmd[loc_cmd_max]();

	main_cmd[0] = Cmd("worker_processes", CMD_TAKE1, mainWorkerProcesses);
	main_cmd[1] = Cmd("worker_connections", CMD_TAKE1, mainWorkerConnections);
	main_cmd[2] = Cmd("client_max_body_size", CMD_TAKE1, mainClientMaxBodySize);

	srv_cmd[0] = Cmd("listen", CMD_TAKE1, serverListen);
	srv_cmd[1] = Cmd("listen", CMD_TAKE1, serverName);
	srv_cmd[2] = Cmd("listen", CMD_TAKE1, serverErrorPage);
	return 0;
}

const Cmd* Conf::getCmdListConst(int loc_type) const {
	if (loc_type == CONF_MAIN)
		return main_cmd;
	if (loc_type == CONF_SRV)
		return srv_cmd;
	if (loc_type == CONF_LOC)
		return loc_cmd;
	return NULL;
}

int Conf::getCmdMaxConst(int loc_type) const {
	if (loc_type == CONF_MAIN)
		return main_cmd_max;
	if (loc_type == CONF_SRV)
		return srv_cmd_max;
	if (loc_type == CONF_LOC)
		return loc_cmd_max;
	return -1;
}

int parseConf(Cycle &cycle, Conf &conf) {
	static_cast<void>(cycle);

	char			buf[1000];
	std::string		tokens[10];
	int				token_cnt;
	std::ifstream&	file = conf.getFile();
	int				cur_location = 0;

	while (file.getline(buf, sizeof(buf))) {
		std::cout << "buf: " << buf << "\n";

		if (buf[0] == '\0')
			continue;

		for (int i = 0; i < 10; i++)
			tokens[i] = '\0';

		token_cnt = tokenizer(buf, tokens);
		if (token_cnt == -1)
			return -1; //error

		if (tokens[0] == "main"	|| tokens[0] == "server") {
			if (tokens[token_cnt - 1] != "{")
				return -1; //error
			cur_location = checkConfLocation(tokens, cur_location);
			if (cur_location == -1)
				return -1; //error
		}

		// for (int i = 0; tokens[i][0]; i++)
		// 	std::cout << tokens[i] << "\n";

		if (cur_location == CONF_MAIN) {
			if (parseMain(cycle, conf.getCmdListConst(CONF_MAIN), \
							conf.getCmdMaxConst(CONF_MAIN), file) == -1) {
				return -1;
			}
		}
		if (cur_location == CONF_SRV) {
			if (parseServer(cycle, conf.getCmdListConst(CONF_SRV), \
							conf.getCmdMaxConst(CONF_SRV), file) == -1) {
				return -1;
			}
		}
		cur_location = 0;
	}

	if(file.eof() == FALSE)
		return -1; // Buffer overflow

	return 0;
}

static int parseMain(Cycle &cycle, const Cmd *cmd, int cmd_max, std::ifstream& file) {
	char			buf[1000];
	std::string		tokens[10];
	int				token_cnt;
	handler_t		handler;

	while (file.getline(buf, sizeof(buf))) {
		if (buf[0] == '\0')
			continue;

		if (static_cast<std::string>(buf) == "}")
			break;
		
		token_cnt = tokenizer(buf, tokens);
		if (token_cnt == -1)
			return -1; //error

		tokens[0] = &tokens[0][1]; //tab으로 시작하니까

		int idx;
		for (idx = 0; idx < cmd_max; idx++) {
			if (cmd[idx].getName() == tokens[0]) {
				if (cmd[idx].getArgCnt() != token_cnt - 1) {
					return -1;
				}
				handler = cmd[idx].getHandler();
				if (handler(cycle, tokens) == -1) {
					return -1; //error
				}
				break;
			}
		}
		if (idx == cmd_max){
			return -1; //directive is not matched
		}
	}
	// std::cout << cycle.getWorkerProcesses() << "\n" \
	// 			<< cycle.getWorkerConnections() << "\n" \
	// 			<< cycle.getClientMaxBodySize() << "\n";

	if (cycle.getWorkerProcesses() == 0 || \
		cycle.getWorkerConnections() == 0 || \
		cycle.getClientMaxBodySize() == 0)
		return -1; //missing directive
	
	return 0;
}

static int parseServer(Cycle &cycle, const Cmd *cmd, int cmd_max, std::ifstream& file) {
	char				buf[1000];
	std::string			tokens[10];
	int					token_cnt;
	handler_t			handler;
	Server				server;

	cycle.getServerList().push_back(server);

	while (file.getline(buf, sizeof(buf))) {
		std::cout << buf << "\n";
		if (buf[0] == '\0')
			continue;
			
		if (static_cast<std::string>(buf) == "}")
			break;
		
		token_cnt = tokenizer(buf, tokens);
		if (token_cnt == -1)
			return -1; //error

		tokens[0] = &tokens[0][1]; //tab으로 시작하니까

		int idx;
		for (idx = 0; idx < cmd_max; idx++) {
			if (cmd[idx].getName() == tokens[0]) {
				if (cmd[idx].getArgCnt() != token_cnt - 1) {
					return -1;
				}
				handler = cmd[idx].getHandler();
				if (handler(cycle, tokens) == -1) {
					return -1; //error
				}
				break;
			}
		}
		if (idx == cmd_max){
			return -1; //directive is not matched
		}
	}
	std::cout << server.getPort() << "\n" \
				<< server.getDomain() << "\n" \
				<< server.getErrorPage() << "\n";

	if (server.getPort() == 0 || \
		server.getDomain() == "" || \
		server.getErrorPage() == "")
		return -1; //missing directive
	return 0;
}

static int checkConfLocation(std::string str[], int cur) {
	if (cur == 0 && str[0] == "main")
		return CONF_MAIN;
	if (cur == 0 && str[0] == "server")
		return CONF_SRV;
	return -1;
}

static int tokenizer(char *str, std::string *tokens) {
	std::istringstream	istr(str);
	std::string			token;
	int					idx = 0;

	while (getline(istr, token, ' ')) {
		if (token.empty() == FALSE) // 공백이 두 개 이상 이어질 때, 공백과 공백 사이에 빈 토큰이 생성됨
			tokens[idx++] = token;
	}
	// getline 실패 시 에러 -1
	return idx;
}