/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/15 20:58:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

HumanB::HumanB(std::string s){
	name = s;
	weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack(void){
	if(!weapon)
		std::cout << name << "'s weapon not set\n";
	else{
		std::cout << name << \
		" attacks with their " << \
		weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& w){
	weapon = &w;
}