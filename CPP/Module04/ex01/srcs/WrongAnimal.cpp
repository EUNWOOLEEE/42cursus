/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:19:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:26:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor called\n";
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "WrongAnimal copy constructor called\n";
	*this = obj;
}

WrongAnimal::WrongAnimal(const std::string _type) : type(_type){
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal& obj){
	std::cout << "WrongAnimal copy assignment operator called\n";
	if(this != &obj) {}
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "None\n";
}

std::string WrongAnimal::getType(void) const{
	return type;
}
