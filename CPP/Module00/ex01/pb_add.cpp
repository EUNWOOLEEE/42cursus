/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:29:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/08/07 09:46:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void pb_add(phonebook *pb)
{
	int idx = pb->cur;
	
	std::cout << "First name: ";
	std::cin >> pb->contact[idx].first_name;

	std::cout << "Last name: ";
	std::cin >> pb->contact[idx].last_name;
	
	std::cout << "Nickname: ";
	std::cin >> pb->contact[idx].nickname;

	std::cout << "Phone number: ";
	std::cin >> pb->contact[idx].number;

	std::cout << "Darkest secret: ";
	std::cin >> pb->contact[idx].secret;

	(*pb).cur = ((*pb).cur + 1) % 8;
	if ((*pb).cnt < 8) (*pb).cnt++;
}