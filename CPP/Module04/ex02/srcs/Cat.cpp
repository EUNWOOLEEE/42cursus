/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:20:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat default constructor called\n";
	brain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj.getType()){
	std::cout << "Cat copy constructor called\n";
	*this = obj;
}

Cat::~Cat(void){
	std::cout << "Cat destructor called\n";
	delete(brain);
}

Cat& Cat::operator =(const Cat& obj){
	std::cout << "Cat copy assignment operator called\n";
	if(this != &obj) {
		delete(brain);
		brain = new Brain();
		brain = obj.brain;
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "     ┏━ ♡ ━━━━ ♡ ━┓\n";
	std::cout << "     ♡    meow!   ♡\n";
	std::cout << "🐱.•O┗━ ♡ ━━━━ ♡ ━┛\n";
}

Brain* Cat::getBrain(void){
	return brain;
}
