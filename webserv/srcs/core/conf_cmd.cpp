# include "cmd.hpp"

int mainWorkerProcesses(Cycle& cycle, std::string tokens[]) {
	int n = stoi(tokens[1]); //catch로 예외처리
	if (n <= 0) //최대 개수 제한은 몇개로?
		return -1;
	cycle.setWorkerProcesses(n);
	return 0;
}

int mainWorkerConnections(Cycle& cycle, std::string tokens[]) {
	int n = stoi(tokens[1]); //catch로 예외처리
	if (n <= 0) //최대 개수 제한은 몇개로?
		return -1;
	cycle.setWorkerConnections(n);
	return 0;
}

int mainClientMaxBodySize(Cycle& cycle, std::string tokens[]) {
	int n = stoi(tokens[1]); //catch로 예외처리
	if (n <= 0) //최대 개수 제한은 몇개로?
		return -1;
	cycle.setClientMaxBodySize(n);
	return 0;
}

int serverListen(Cycle& cycle, std::string tokens[]) {
	int n = stoi(tokens[1]);
	if (n <= 0) // 포트 범위??
		return -1;
	cycle.getServerList().back().setPort(n);
	return 0;
}

int serverName(Cycle& cycle, std::string tokens[]) {
	cycle.getServerList().back().setDomain(tokens[1]);
	return 0;
}

int serverErrorPage(Cycle& cycle, std::string tokens[]) {
	cycle.getServerList().back().setErrorPage(tokens[1]);
	return 0;
}
