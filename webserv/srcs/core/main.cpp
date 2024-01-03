#include "core.hpp"

int error_code;

int main(int argc, char **argv, char **envp) {
	(void)envp;

	Cycle cycle;
	Conf conf;

	try{
		setConf(cycle, conf, argc, argv[1]);
		parseConf(cycle, conf);
	} catch(Exception& e){
		std::cerr << e.what() << std::endl; //에러 기록용 파일?? 표준 에러?
		if (errno != 0)
			std::cerr << ": " << strerror(errno) << std::endl;
		return error_code;
	}
	createWorker(cycle);
	return 0;
}
