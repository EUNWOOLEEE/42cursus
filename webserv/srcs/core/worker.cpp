#include "core.hpp"

Worker::Worker(int id) : worker_id(id) {
	event_queue = kqueue();
	if (event_queue == -1)
		setException(WORK_CREATE_KQ_FAIL);
	listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listen_socket == -1)
		setException(WORK_CREATE_SOCKET_FAIL);
}

Worker::Worker(const Worker& src) {
	*this = src;
}

Worker::~Worker(void) {}

Worker& Worker::operator =(const Worker& src) {
	if (this != &src) {
		worker_id = src.worker_id;
		event_queue = src.event_queue;
		listen_socket = src.listen_socket;
	}
	return (*this);
}

int	Worker::getWorkerId(void) const {
	return worker_id;;
}

int	Worker::getEventQueue(void) const {
	return event_queue;
}

int	Worker::getListenSocket(void) const {
	return listen_socket;
}

void createWorker(Cycle &cycle) {
	worker_array	worker_list = cycle.getWorkerList();

	for (int i = 0; i < WORKER_PROCESS_MAX; i++) {
		worker_list[i] = fork();
		if (worker_list[i] == 0) {
			try {
				prepConnect(cycle, i);
			} catch(Exception& e){
				std::cerr << e.what() << std::endl; //에러 기록용 파일?? 표준 에러?
				//부모에게 에러코드 전달?
			}
		}
	}
}
