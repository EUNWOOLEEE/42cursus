/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:44:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 19:52:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"

Weapon::Weapon(void){}

Weapon::Weapon(std::string str){
	type = str;
}

Weapon::~Weapon(void){}

const std::string&	Weapon::getType(){
	return type;
}

void	Weapon::setType(std::string newType){
	type = newType;
}