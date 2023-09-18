/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:52:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/18 18:22:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Phonebook.hpp"

int main(){
	Phonebook pb = Phonebook();
	std::string cmd;

	while(true){
		std::cout << "Enter a command [ADD][SEARCH][EXIT]" << std::endl;
		std::getline(std::cin, cmd);
		if(std::cin.eof() == true)
			std::exit(0);
		
		if(cmd == "ADD")
			pb.pb_add(pb);
		else if (cmd == "SEARCH")
			pb.pb_search(pb);
		else if (cmd == "EXIT")
			pb.pb_exit();
	}
	return (0);
}