#include "Response.hpp"
#include "../utils/Status.hpp"

Status	status_line[] = {
	{"200", "OK"},
	{"201", "Created"},
	{"202", "Accepted"},
	{NULL, NULL},
	{"204", "No Content"},
	{NULL, NULL},
	{NULL, NULL},
	{"301", "Moved Permanently"},
	{"302", "Found"},
	{"303", "See Other"},
	{"304", "Not Modified"},
	{NULL, NULL},
	{NULL, NULL},
	{"307", "Temporary Redirect"},
	{"308", "Permanent Redirect"},
	{"400", "Bad Request"},
	{"401", "Unathorized"},
	{NULL, NULL},
	{"403", "Forbidden"},
	{"404", "Not Found"},
	{"405", "Method Not Allowed"},
	{"406", "Not Acceptable"},
	{NULL, NULL},
	{"408", "Request Timeout"},
	{"409", "Conflict"},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{"413", "Content Too Large"},
	{"414", "URI Too Long"},
	{"415", "Unsupported Media Type"},
	{NULL, NULL},
	{"417", "Expectation Failed"},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{NULL, NULL},
	{"500", "Internal Server Error"},
	{"501", "Not Implemented"},
	{"502", "Bad Gateway"},
	{"503", "Service Unavailable"},
	{"504", "Gateway Timeout"},
	{"505", "HTTP Version Not Supported"},
	{"100", "Continue"}
};

Response::Response()
{
	body_flag = false;
}

Response::~Response() {}

void	Response::reset_data()
{
	header_line.clear();
	header.clear();
	headers.clear();
	body.clear();
	response_msg.clear();
	body_flag = false;
}

void	Response::assemble_message()
{
	response_msg = get_header_line();
	response_msg += get_header_field();
	response_msg += "\r\n";
	if (body_flag == true)
	{
		response_msg += get_body();
		set_body ("");
	}
}

std::string	&Response::get_header_line () {return this->header_line;}

std::string	&Response::get_header_field ()
{
	std::map<std::string, std::string>::iterator	it = header.begin();
	std::map<std::string, std::string>::iterator	ite = header.end();

	for (; it != ite; it++)
		headers += it->first + ": " + it->second + "\r\n";

	return headers;
}

std::string	Response::get_header_field (const char *key)
{
	if (header.find(key) != header.end())
		return header[key];
	return "500";
}

std::string	&Response::get_body() {return this->body;}

void	Response::set_header_line (int status_code)
{
	int status = status_code;

	if (OK <= status && status < LAST_2XX)
		status -= OK;
	else if (MOVED_PERMANENTLY <= status && status < LAST_3XX)
		status = status - MOVED_PERMANENTLY + OFF_3XX;
	else if (BAD_REQUEST <= status && status < LAST_4XX)
		status = status - BAD_REQUEST + OFF_4XX;
	else
		status = status - INTERNAL_SERVER_ERROR + OFF_5XX;

	if (status_code == CONTINUE)
		status = 51;

	header_line = "HTTP/1.1 ";
	header_line += status_line[status].code;
	header_line += " ";
	header_line += status_line[status].text;
	header_line += "\r\n";

}

void	Response::set_header_field (const std::string &key, const std::string &value)
{
	header[key] = value;
}

void	Response::set_header_field (const std::string &key_value)
{
	std::string key = key_value.substr(0, key_value.find(":"));
	std::string	value = key_value.substr(key_value.find(": ") + 2);

	header[key] = value;
}

void	Response::set_body(std::string body)
{
	this->body = body;
	body_flag = true;
}

std::string &Response::get_response_message() {
	return response_msg;
}
