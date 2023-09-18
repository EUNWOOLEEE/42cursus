/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:02:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/18 18:19:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Phonebook.hpp"

static void get_line(std::string& str, std::string& arr);
static bool	check_space(std::string str);

std::string Contact::get_info(int i){
	return info_arr[i];
}

void	Contact::add_info(void){
	std::cout << "First name: ";
	get_line(first_name, info_arr[0]);

	std::cout << "Last name: ";
	get_line(last_name, info_arr[1]);
	
	std::cout << "Nickname: ";
	get_line(nickname, info_arr[2]);

	std::cout << "Phone number: ";
	get_line(number, info_arr[3]);

	std::cout << "Darkest secret: ";
	get_line(secret, info_arr[4]);
}

static void get_line(std::string& str, std::string& arr){
	str.clear();
	while(check_space(str) == true){
		std::getline(std::cin, str);
		if (std::cin.eof() == true)
			std::exit(0);
	}
	arr = str;
}

static bool	check_space(std::string str){
	for(unsigned long i = 0; i < str.size(); i++)
		if(isspace(str[i]) == false)
			return false;
	return true;
}