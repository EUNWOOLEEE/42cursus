/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:19:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 14:42:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

Animal::Animal(void){
	std::cout << "Animal default constructor called\n";
	type = "Animal";
}

Animal::Animal(const Animal& obj){
	std::cout << "Animal copy constructor called\n";
	*this = obj;
}

Animal::~Animal(void){
	std::cout << "Animal destructor called\n";
}

Animal& Animal::operator =(const Animal& obj){
	std::cout << "Animal copy assignment operator called\n";
	if(this != &obj)
		type = obj.type;
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "None\n";
}

std::string Animal::getType(void) const{
	return type;
}
