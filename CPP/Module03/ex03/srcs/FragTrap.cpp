/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:40:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 18:48:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap(){	
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name){	
	std::cout << "FragTrap init constructor called\n";
	hp = 100;
	ep = 100;
	ad = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj.name){
	std::cout << "FragTrap copy constructor called\n";
	*this = obj;
}

FragTrap::~FragTrap(){	
	std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator =(const FragTrap& src){
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &src){
		name = src.name;
		hp = src.hp;
		ep = src.ep;
		ad = src.ad;
	}
	return *this;
}

void FragTrap::attack(const std::string& target){
	std::cout << "FragTrap " << name << " attacks " << target << "\n";
	std::cout << name << "'s hp: " << hp << " ep: " << --ep << "\n";
}

void FragTrap::_attack(FragTrap& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else if(target.hp < ad)
		std::cout << target.name << " is already dead!\n";
	else{
		attack(target.name);
		target.takeDamage(ad);
	}
}

void FragTrap::highFivesGuys(void){	
	std::cout << name << " : Let's highfive 🖐️\n";
}

