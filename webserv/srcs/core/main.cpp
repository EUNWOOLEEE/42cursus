#include "core.hpp"

int error_code;

int main(int argc, char **argv, char **envp) {
	(void)envp;

	Cycle cycle;
	Conf conf;

	// if (argc != 1 && argc != 2)
	if (argc != 2) //default 설정 파일 세팅 안함
		return -1; // error

	try{
		conf = Conf(argv[1]);
		parseConf(cycle, conf);
		createWorker(cycle);
	} catch(Exception& e){
		std::cerr << e.what() << std::endl; //에러 기록용 파일?? 표준 에러?
		if (errno != 0)
			std::cerr << ": " << strerror(errno) << std::endl;
		return error_code;
	}
	return 0;
}
