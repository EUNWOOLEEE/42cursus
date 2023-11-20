/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:20:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 18:15:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	std::cout << "Ice default constructor called\n";
	type = "ice";
}

Ice::Ice(const Ice& obj){
	std::cout << "Ice copy constructor called\n";
}

Ice::~Ice(void){
	std::cout << "Ice destructor constructor called\n";
}

Ice& Ice::operator =(const Ice& obj){
	std::cout << "Ice copy assignment operator called\n";
}
