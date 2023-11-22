/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:24:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 18:25:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ICharacter.hpp"

AMateria::AMateria(void){
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const AMateria& obj){
	std::cout << "AMateria copy constructor called\n";
	*this = obj;
}

AMateria::AMateria(std::string const & _type) : type(_type){
	std::cout << "AMateria constructor called\n";
}

AMateria::~AMateria(void){
	std::cout << "AMateria destructor called\n";
}

AMateria& AMateria::operator =(const AMateria& obj){
	std::cout << "AMateria copy assignment operator called\n";
	if(this != &obj)
		type = obj.getType();
	return *this;
}

std::string const & AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Use at " << target.getName() << "\n";
}
