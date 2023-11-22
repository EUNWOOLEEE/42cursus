/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:20:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:27:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& obj) : AMateria("ice"){
	std::cout << "Ice copy constructor called\n";
	*this = obj;
}

Ice::~Ice(void){
	std::cout << "Ice destructor constructor called\n";
}

Ice& Ice::operator =(const Ice& obj){
	std::cout << "Ice copy assignment operator called\n";
	if(this != &obj)
		type = obj.getType();
	return (*this);
}

AMateria* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
