/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:01:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 11:58:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

Harl::Harl(){
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
}

void	Harl::complain(std::string level){
	int	value = (1 * (level == "DEBUG")) + (2 * (level == "INFO")) + (3 * (level == "WARNING")) + (4 * (level == "ERROR"));

	switch (value)
	{
	case 1:
		(this->*func[0])();
		//FALLTHROUGH
	case 2:
		(this->*func[1])();
		//FALLTHROUGH
	case 3:
		(this->*func[2])();
		//FALLTHROUGH
	case 4:
		(this->*func[3])();
		break;
	default:
		std::cout << OTHER_MSG;
		break;
	}
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
