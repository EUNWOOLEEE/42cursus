/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 01:09:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string _name){
	std::cout << "ClapTrap init constructor called\n";
	name = _name;
	hp = 10;
	ep = 10;
	ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj){
	std::cout << "ClapTrap copy constructor called\n";
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap& ClapTrap::operator =(const ClapTrap& src){
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &src){
		name = src.name;
		hp = src.hp;
		ep = src.ep;
		ad = src.ad;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else{
		std::cout << "ClapTrap " << name << " attacks " << target \
					<< ", causing " << ad << " points of damage!" << "\n";
		ep--;
	}
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

void ClapTrap::takeDamage(unsigned int amount){
	if(!hp)
		std::cout << name << " is already dead!\n";
	else{
		std::cout << "ClapTrap " << name \
					<< " is attacked, lose of " << amount << " hp!\n";
		if (hp < (int)amount)
			hp = 0;
		else
			hp -= amount;
	}
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

void ClapTrap::beRepaired(unsigned int amount){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else{
		std::cout << "ClapTrap " << name \
				<< " be repaired, get of " << amount << " hp!\n";
		ep--;
		hp += amount;
	}
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

