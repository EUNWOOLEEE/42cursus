/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 14:44:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(void){
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& obj){
	std::cout << "Cat copy constructor called\n";
	*this = obj;
}

Cat::~Cat(void){
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator =(const Cat& obj){
	std::cout << "Cat copy assignment operator called\n";
	if(this != &obj)
		type = obj.type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "     ┏━ ♡ ━━━━ ♡ ━┓\n";
	std::cout << "     ♡    meow!   ♡\n";
	std::cout << "🐱.•O┗━ ♡ ━━━━ ♡ ━┛\n";
}

std::string Cat::getType(void) const{
	return type;
}
