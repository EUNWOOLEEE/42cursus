/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 17:48:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat default constructor called\n";
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
