/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:01:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/23 18:24:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

Harl::Harl(){
	cmd[0] = "DEBUG";
	cmd[1] = "INFO";
	cmd[2] = "WARNING";
	cmd[3] = "ERROR";

	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
}

void	Harl::complain(std::string level){
	bool	flag = false;
	for(int i = 0; i < 4; i++){
		if(level == cmd[i])
			flag = true;
		if(flag == true)
			(this->*func[i])();
	}
	if(flag == false)
		std::cout << OTHER_MSG;
}

void	Harl::debug(void){
	std::cout << "[ DEBUG ]\n" << DEBUG_MSG;
}

void	Harl::info(void){
	std::cout << "[ INFO ]\n"  << INFO_MSG;
}

void	Harl::warning(void){
	std::cout << "[ WARNING ]\n"  << WARNING_MSG;
}

void	Harl::error(void){
	std::cout << "[ ERROR ]\n"  << ERROR_MSG;
}
