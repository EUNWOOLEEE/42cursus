/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:57:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/10 19:59:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	phonebook::pb_add(phonebook *pb){
	int idx = pb->cur;
	contact *info = pb->get_contact(idx);
	
	info->add_info();

	(*pb).cur = ((*pb).cur + 1) % 8;
	if ((*pb).cnt < 8) (*pb).cnt++;
}

void	contact::add_info(void){
	std::cout << "First name: ";
	if (!(std::cin >> first_name))
		exit(0);
	info_arr[0] = first_name;

	std::cout << "Last name: ";
	if (!(std::cin >> last_name))
		exit(0);
	info_arr[1] = last_name;
	
	std::cout << "Nickname: ";
	if (!(std::cin >> nickname))
		exit(0);
	info_arr[2] = nickname;

	std::cout << "Phone number: ";
	if (!(std::cin >> number))
		exit(0);
	info_arr[3] = number;

	std::cout << "Darkest secret: ";
	if (!(std::cin >> secret))
		exit(0);
	info_arr[4] = secret;
}