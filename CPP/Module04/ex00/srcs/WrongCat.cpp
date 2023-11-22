/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:21:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj.getType()){
	std::cout << "WrongCat copy constructor called\n";
	*this = obj;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator =(const WrongCat& obj){
	std::cout << "WrongCat copy assignment operator called\n";
	if(this != &obj)
		type = obj.type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "     ┏━ ♡ ━━━━ ♡ ━┓\n";
	std::cout << "     ♡    meow!   ♡\n";
	std::cout << "🐱.•O┗━ ♡ ━━━━ ♡ ━┛\n";
}
