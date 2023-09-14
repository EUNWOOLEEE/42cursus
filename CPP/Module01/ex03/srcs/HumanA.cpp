/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/15 06:48:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"

HumanA::HumanA(std::string s, Weapon& w) : name(s), weapon(w){}

HumanA::~HumanA(){}

void	HumanA::attack(void){
	std::cout << name << \
	" attacks with their " << \
	weapon.getType() << std::endl;
}