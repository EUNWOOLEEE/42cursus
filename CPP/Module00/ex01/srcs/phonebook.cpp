/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:14:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/13 21:23:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

static void print_name(std::string name);
static void show_all(Phonebook pb);
static void	show_specific(Phonebook pb);

Contact *Phonebook::get_contact(int i){
	return &contacts[i];
}

void	Phonebook::pb_add(Phonebook *pb){
	int idx = pb->cur;
	Contact *info = pb->get_contact(idx);
	
	info->add_info();

	(*pb).cur = ((*pb).cur + 1) % 8;
	if ((*pb).cnt < 8) (*pb).cnt++;
}

void Phonebook::pb_exit(void){
	exit(0);
}

void Phonebook::pb_search(Phonebook pb){
	if(!pb.cnt){
		std::cout << "No Contacts" << std::endl;
		return ;
	}
	
	show_all(pb);
	show_specific(pb);
}

static void print_name(std::string name){
	int cnt = 10 - name.length();
	
	if(cnt > 0){
		for(int k = 0; k < cnt; k++) std::cout << " ";
		std::cout << name;
	}
	else if (cnt < 0){
		std::string sub = name.substr(0, 9);
		std::cout << sub << ".";
	}
	else
		std::cout << name;
}

static void show_all(Phonebook pb){
	int i = pb.cnt < 8 ? 0 : pb.cur;
	
	for(int j = 0; j < pb.cnt; j++){
		Contact *info = pb.get_contact(i);
		
		std::cout << "[" << j << "]";
		std::cout << " | ";
		
		for(int k = 0; k < 3; k++){
			print_name(info->get_info(k));
			if (k < 2)
				std::cout << " | ";
			else
				std::cout << std::endl;
		}

		i = (i + 1) % 8;
	}
}

static void	show_specific(Phonebook pb){
	std::cout << "Select an index to display" << std::endl;

	int idx;
	
	if (!(std::cin >> idx))
		exit(0);
	

	int i = pb.cnt < 8 ? 0 + idx : (pb.cur + idx) % 8;

	if (0 <= idx && idx < pb.cnt){
		Contact *info = pb.get_contact(i);
		for (int j = 0; j < 5; j++){
			print_name(info->get_info(j));
			if (j < 4)
				std::cout << " | ";
			else
				std::cout << std::endl;
		}
	}
	else
		std::cout << "Wrong index" << std::endl;
}