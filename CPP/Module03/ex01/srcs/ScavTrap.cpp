/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 19:00:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "Default constructor called\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name){
	std::cout << "Init constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor called\n";
}

ScavTrap& ScavTrap::operator =(const ScavTrap& src){
	std::cout << "Copy assignment operator called\n";
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
