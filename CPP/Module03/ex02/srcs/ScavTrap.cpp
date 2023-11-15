/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 20:52:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name){
	std::cout << "ScavTrap init constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj){
	std::cout << "ScavTrap copy constructor called\n";
	*this = obj;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator =(const ScavTrap& src){
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &src){
		set_name(src.get_name());
		set_hp(src.get_hp());
		set_ep(src.get_ep());
		set_ad(src.get_ad());
	}
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << get_name() << " in Gate Keeper mode\n";
}
