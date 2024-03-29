#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include <string>
#include <unistd.h>
#include <exception>

static void			handleGetMethod(const std::string directory_path, const std::string get_data);
static void			handlePostMethod(const std::string directory_path, const std::string post_data);
static void			handleSignal(int);
static std::string	getEnvString(const char* str);
static std::string	createUniqueFileName();

int main() {

	signal(SIGTERM, handleSignal);

	try {
		// while (1) {} // 무한루프 테스트
		std::string			data_post;
		std::string			request_method = getEnvString("REQUEST_METHOD");
		const std::string	data_get = getEnvString("QUERY_STRING_GET");
		const std::string	directory_path = getEnvString("REDIRECT_PATH");

		while (std::getline(std::cin, data_post)) {}
		if (request_method == "GET")
			handleGetMethod(directory_path, data_get);
		else if (request_method == "POST")
			handlePostMethod(directory_path, data_post);
	}
	catch(std::exception& e) {
		return 1;
	}
	return 0;
}

static void handleGetMethod(const std::string directory_path, const std::string get_data) {
	std::ifstream		file(directory_path + get_data);
	std::stringstream	ss;

	if (file.is_open() == false) {
		std::cout << "Status_code: 404\r\n";
		return ;
	}

	ss << file.rdbuf();

	std::cout << "Content-Type: text/plain\r\n";
	std::cout << "Status_code: 200\r\n";
	std::cout << "\r\n";
	std::cout << ss.str();
	std::cout << "\r\n";
}

static void handlePostMethod(const std::string directory_path, const std::string post_data) {
	std::cout << "Content-Type: text/plain\r\n";

	if (post_data.length() > 0) {

		std::string		new_file_name = createUniqueFileName();
		std::ofstream	new_file(std::string(directory_path) + new_file_name);

		if (new_file.is_open() == false)
			throw std::runtime_error("open");

		new_file << post_data;
		new_file.close();

		std::cout << "Status_code: 201\r\n";
	}
}

static void handleSignal(int signum) {
	static_cast<void>(signum);
	exit(1);
}

static std::string getEnvString(const char* str) {
	const char*	tmp = getenv(str);

	if (tmp == NULL)
		throw std::runtime_error("getenv");

	return std::string(tmp);
}

static std::string createUniqueFileName() {
	time_t		now = time(nullptr);
	struct tm*	timeinfo = localtime(&now);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", timeinfo);

	return std::string(buffer) + ".txt";
}
