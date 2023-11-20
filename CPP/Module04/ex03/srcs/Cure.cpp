/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:20:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 17:22:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	std::cout << "Cure default constructor called\n";
	type = "cure";
}

Cure::Cure(const Cure& obj){
	std::cout << "Cure copy constructor called\n";
}

Cure::~Cure(void){
	std::cout << "Cure destructor constructor called\n";
}

Cure& Cure::operator =(const Cure& obj){
	std::cout << "Cure copy assignment operator called\n";
}

//이거 수정하기
AMateria* clone() const{
	return new Cure();
}
