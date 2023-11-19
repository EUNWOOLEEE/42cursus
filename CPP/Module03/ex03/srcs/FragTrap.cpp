/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:40:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 15:49:16 by eunwolee         ###   ########.fr       */
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
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void FragTrap::attack(const std::string& target){
	if(!hp)
		std::cout << name << " has no hp!\n";
	else if(!ep)
		std::cout << name << " has no ep!\n";
	else{
		std::cout << "FragTrap " << name << " attacks " << target \
					<< ", causing " << ad << " points of damage!" << "\n";
		ep--;
	}
	std::cout << name << "'s hp: " << hp << " ep: " << ep << "\n";
}

void FragTrap::highFivesGuys(void){	
	std::cout << name << " : Let's highfive 🖐️\n";
}
