/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 14:43:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(void){
	std::cout << "Dog default constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& obj){
	std::cout << "Dog copy constructor called\n";
	*this = obj;
}

Dog::~Dog(void){
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator =(const Dog& obj){
	std::cout << "Dog copy assignment operator called\n";
	if(this != &obj)
		type = obj.type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "     ┏━ ♡ ━━━━ ♡ ━┓\n";
	std::cout << "     ♡ woof-woof! ♡\n";
	std::cout << "🐶.•O┗━ ♡ ━━━━ ♡ ━┛\n";
}

std::string Dog::getType(void) const{
	return type;
}
