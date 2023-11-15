/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 19:13:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string _name){
	std::cout << "Init constructor called\n";
	name = _name;
	hp = 100;
	ep = 50;
	ad = 20;
}

ClapTrap::ClapTrap(const ClapTrap& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called\n";
}

ClapTrap& ClapTrap::operator =(const ClapTrap& src){
	std::cout << "Copy assignment operator called\n";
	if (this != &src){
		name = src.name;
		hp = src.hp;
		ep = src.ep;
		ad = src.ad;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap " << name << " attacks " << target << "\n";
	ep--;
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << name \
				<< " is attacked, lose of " << amount << " hp!\n";
	hp -= amount;
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

void ClapTrap::_attack(ClapTrap& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else if(target.get_hp() < ad)
		std::cout << target.get_name() << " is already dead!\n";
	else{
		attack(target.name);
		target.takeDamage(ad);
	}
}

void ClapTrap::set_name(const std::string _name){
	name = _name;
}

void ClapTrap::set_hp(const int _hp){
	hp = _hp;
}

void ClapTrap::set_ep(const int _ep){
	ep = _ep;
}

void ClapTrap::set_ad(const int _ad){
	ad = _ad;
}

std::string ClapTrap::get_name(void) const{
	return name;
}

int ClapTrap::get_hp(void) const{
	return hp;
}

int ClapTrap::get_ep(void) const{
	return ep;
}

int ClapTrap::get_ad(void) const{
	return ad;
}
