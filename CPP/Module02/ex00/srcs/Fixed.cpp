/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:03:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 20:15:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed(){
	fix = 0;
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const{
	return fix;
}

void Fixed::setRawBits(int const raw){
	fix = raw;
}