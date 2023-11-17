/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 08:47:31 by eunwolee         ###   ########.fr       */
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
	if(this != &obj) {}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "woof-woof!🐶\n";
}
