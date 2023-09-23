/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:44:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/21 17:58:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Sed.hpp"

Sed::Sed(char *file_name, char* str1, char* str2){
	file.open(file_name, std::ios_base::in);
	if(!file){
		throw Exception("File open error!");
	}

	std::string copy_file_name = std::string(file_name).append(".replace");
	copy_file.open(copy_file_name, std::ios_base::out);
	if(!copy_file){
		file.close();
		throw Exception("File create error!");
	}

	orignal_str = (std::string)str1;
	replace_str = (std::string)str2;
}

Sed::~Sed(){
	if(file)
		file.close();
	if(copy_file)
		copy_file.close();
}

void	Sed::rewrite(){
	char	buf[3];

	while(file.getline(buf, sizeof(buf))){
		std::string buf_tmp = (std::string)buf;
		int			compare = 0;

		for(u_int64_t i = 0; i < buf_tmp.length(); i++){
			compare = buf_tmp.find(orignal_str, i);
			if(compare >= 0){
				buf_tmp.erase(compare, orignal_str.length());
				buf_tmp.insert(compare, replace_str);
				i = compare + replace_str.length() - 1;
			}
		}
		if(file.eof() == false)
			buf_tmp.append("\n");

		copy_file.write(buf_tmp.c_str(), buf_tmp.length());
	}
	if(file.eof() == false)
		throw Exception("Buffer overflow!");
}

/*Exception*/

Exception::Exception(const std::string& msg) : msg_(msg) {}

const char*	Exception::what() const {
	return msg_.c_str();
}