/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 15:20:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name){
	std::cout << "ScavTrap init constructor called\n";
	hp = 100;
	ep = 50;
	ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj.name){
	std::cout << "ScavTrap copy constructor called\n";
	*this = obj;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator =(const ScavTrap& src){
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void ScavTrap::attack(const std::string& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else{
		std::cout << "ScavTrap " << name << " attacks " << target \
					<< ", causing " << ad << " points of damage!" << "\n";
		ep--;
	}
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

void ScavTrap::guardGate(){
	std::cout << name << " in Gate Keeper mode\n";
}
