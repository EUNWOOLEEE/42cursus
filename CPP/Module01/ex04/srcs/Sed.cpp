/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:44:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/20 18:54:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Sed.hpp"

Sed::Sed(char *file_name, char *copy_file_name){
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
}