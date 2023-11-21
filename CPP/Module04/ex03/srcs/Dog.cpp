/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/21 16:17:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog default constructor called\n";
	brain = new Brain();
}

Dog::Dog(const Dog& obj){
	std::cout << "Dog copy constructor called\n";
	*this = obj;
}

Dog::~Dog(void){
	std::cout << "Dog destructor called\n";
	delete(brain);
}

Dog& Dog::operator =(const Dog& obj){
	std::cout << "Dog copy assignment operator called\n";
	if(this != &obj) {
		delete(brain);
		brain = new Brain();
		brain = obj.brain;
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "     ┏━ ♡ ━━━━ ♡ ━┓\n";
	std::cout << "     ♡ woof-woof! ♡\n";
	std::cout << "🐶.•O┗━ ♡ ━━━━ ♡ ━┛\n";
}

Brain* Dog::getBrain(void){
	return brain;
}
