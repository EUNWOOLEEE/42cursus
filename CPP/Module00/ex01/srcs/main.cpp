/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:52:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/13 20:34:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(){
	phonebook pb = phonebook();
	std::string cmd;

	while (true){
		std::cout << "Enter a command [ADD][SEARCH][EXIT]" << std::endl;
		if (!(std::cin >> cmd))
			exit(0);
		
		if (cmd == "ADD")
			pb.pb_add(&pb);
		else if (cmd == "SEARCH")
			pb.pb_search(pb);
		else if (cmd == "EXIT")
			pb.pb_exit();
	}
	return (0);
}