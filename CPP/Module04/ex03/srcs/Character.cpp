/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:05:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/21 16:27:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Charcater.hpp"

Character::Character(void){
	std::cout << "Character default constructor called\n";
}

Character::Character(const Character& obj){
	std::cout << "Character copy constructor called\n";
	*this = obj;
}

Character::Character(std::string const & _name) \
			: name(_name), slot{AMateria(), AMateria(), AMateria(), AMateria()}{
	std::cout << "Character constructor called\n";
}
    
Character::~Character(void){
	std::cout << "Character destructor called\n";
}


Character& Character::operator =(const Character& obj){
	std::cout << "Character copy assignment operator called\n";
	if(this != *obj){
		name = obj.name;
	}
	return this;
}


std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m){

}

void Character::unequip(int idx){

}

void Character::use(int idx, ICharacter& target){

}
