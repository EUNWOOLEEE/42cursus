/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_search.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:11:23 by eunwolee          #+#    #+#             */
/*   Updated: 2023/08/07 10:03:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void print_name(std::string name);

void pb_search(phonebook pb)
{
	int i = pb.cnt < 8 ? 0 : pb.cur;
	
	for(int j = 0; j < pb.cnt; j++)
	{
		std::cout << "[" << j << "]";
		std::cout << " | ";
		
		print_name(pb.contact[i].first_name);
		std::cout << " | ";
		
		print_name(pb.contact[i].last_name);
		std::cout << " | ";

		print_name(pb.contact[i].nickname);
		std::cout << std::endl;
		
		i = (i + 1) % 8;
	}	
	
	std::cout << "Select an index to display" << std::endl;
	int idx;
	std::cin >> idx;
	i = pb.cnt < 8 ? 0 + idx : (pb.cur + idx) % 8;

	if (0 <= idx && idx <= pb.cnt)
	{
		print_name(pb.contact[idx].first_name);
		std::cout << " | ";
		
		print_name(pb.contact[idx].last_name);
		std::cout << " | ";

		print_name(pb.contact[idx].nickname);
		std::cout << " | ";

		print_name(pb.contact[idx].number);
		std::cout << " | ";
		
		print_name(pb.contact[idx].secret);
		std::cout << std::endl;
	}
	else
		std::cout << "Wrong index" << std::endl;
}

static void print_name(std::string name)
{
	int cnt = 10 - name.length();
	if(cnt > 0)
	{
		for(int k = 0; k < cnt; k++) std::cout << " ";
		std::cout << name;
	}
	else if (cnt < 0)
	{
		std::string sub = name.substr(0, 9);
		std::cout << sub << ".";
	}
	else
		std::cout << name;
}