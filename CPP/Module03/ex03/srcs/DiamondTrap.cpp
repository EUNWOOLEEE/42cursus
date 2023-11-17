/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:51:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 18:32:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "DiamondTrap dDefault constructor called\n";
}

DiamondTrap::DiamondTrap(std::string _name) \
		: ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name){
	std::cout << "DiamondTrap init constructor called\n";
	name = _name;
	hp = 100;
	ep = 50;
	ad = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) \
		: ClapTrap(obj.name + "_clap_name"), ScavTrap(obj.name), FragTrap(obj.name){
	std::cout << "DiamondTrap copy constructor called\n";
	*this = obj;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap& DiamondTrap::operator =(const DiamondTrap& src){
	std::cout << "DiamondTrap copy assignment operator called\n";
	if (this != &src){
		ClapTrap::operator=(src);
		name = src.name;
	}
	return *this;
}

void DiamondTrap::_attack(DiamondTrap& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else if(target.hp < ad)
		std::cout << target.name << " is already dead!\n";
	else{
		ScavTrap::attack(target.name);
		target.takeDamage(ad);
	}
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap's name is " << name \
				<< ", ClapTrap's name is " << ClapTrap::name << "\n";
}
