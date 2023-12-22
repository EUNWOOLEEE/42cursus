#include "core.hpp"

int main(int argc, char **argv, char **envp) {
	(void)envp;

	Cycle cycle;
	Conf conf;

	// if (argc != 1 && argc != 2)
	if (argc != 2) //default 설정 파일 세팅 안함
		return 0; // error

	try{
		conf = Conf(argv[1]);
	} catch(Exception& e){
		std::cerr << e.what() << std::endl;
		return 0; //error code
	}
	if (parseConf(cycle, conf) == FALSE)
		// return 0;

	return 0;
}
