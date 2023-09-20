/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:38:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/20 18:39:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Sed.hpp"

void	rewrite(std::ifstream& file, std::ofstream& copy_file, std::string str1, std::string str2);

bool	check_error(int argc, char **argv){
	if(argc != 4){
		std::cout << "Usage: filename str1 str2\n";
		return true;
	}
	if(!argv[2][0] || !argv[3][0]){
		std::cout << "String must not be empty\n";
		return true;
	}
	return false;
}

int	main(int argc, char **argv){
	if(check_error(argc, argv) == true)
		return 0;

	std::ifstream	file(argv[1]);
	if(!file){
		std::cout << "File open error!\n";
		return 0;
	}

	std::string		file_name = std::string(argv[1]).append(".replace");
	std::ofstream	copy_file(file_name);
	if(!copy_file){
		std::cout << "File create error!\n";
		return 0;
	}

	rewrite(file, copy_file, (std::string)argv[2], (std::string)argv[3]);
}

void	rewrite(std::ifstream& file, std::ofstream& copy_file, std::string str1, std::string str2){
	char	buf[1000];

	while(file.getline(buf, sizeof(buf))){
		std::string buf_tmp = (std::string)buf;
		int			compare = 0;

		for(u_int64_t i = 0; i < buf_tmp.length(); i++){
			compare = buf_tmp.find(str1, i);
			if(compare >= 0){
				buf_tmp.erase(compare, str1.length());
				buf_tmp.insert(compare, str2);
				i = compare + str2.length() - 1;
				std::cout << i << ": " << buf_tmp[i + 1] << std::endl;
			}
		}
		if(file.eof() == false)
			buf_tmp.append("\n");

		copy_file.write(buf_tmp.c_str(), buf_tmp.length());
	}
}

/* hello world hi
hello yuza world
world worldworld

./Sed out world hi
./Sed out world " "
./Sed out " " world */