/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:40:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 20:53:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap(){	
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name){	
	std::cout << "FragTrap init constructor called\n";
}

FragTrap::FragTrap(const FragTrap& obj){	
	std::cout << "FragTrap copy constructor called\n";
	*this = obj;
}

FragTrap::~FragTrap(){	
	std::cout << "FragTrap destructor called\n";
}


FragTrap& FragTrap::operator =(const FragTrap& src){	
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &src){
		set_name(src.get_name());
		set_hp(src.get_hp());
		set_ep(src.get_ep());
		set_ad(src.get_ad());
	}
	return *this;
}


void FragTrap::highFivesGuys(void){	
	std::cout << get_name() << " : Let's highfive 🖐️\n";
}

