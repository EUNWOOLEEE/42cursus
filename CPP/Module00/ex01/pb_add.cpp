/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:57:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/13 08:49:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void get_line(std::string *str, std::string *arr);

void	phonebook::pb_add(phonebook *pb){
	int idx = pb->cur;
	contact *info = pb->get_contact(idx);
	
	info->add_info();

	(*pb).cur = ((*pb).cur + 1) % 8;
	if ((*pb).cnt < 8) (*pb).cnt++;
}

void	contact::add_info(void){
	std::cin.ignore();
	std::cout << "First name: ";
	get_line(&first_name, &info_arr[0]);

	std::cout << "Last name: ";
	get_line(&last_name, &info_arr[1]);
	
	std::cout << "Nickname: ";
	get_line(&nickname, &info_arr[2]);

	std::cout << "Phone number: ";
	get_line(&number, &info_arr[3]);

	std::cout << "Darkest secret: ";
	get_line(&secret, &info_arr[4]);
}

static void get_line(std::string *str, std::string *arr){
	while (str->empty() == true || std::all_of(str->begin(), str->end(), isspace) == true)
	{
		std::getline(std::cin, *str);
		if (std::cin.eof() == true)
			exit(0);
	}
	*arr = *str;
}