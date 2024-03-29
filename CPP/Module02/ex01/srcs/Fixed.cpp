/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:03:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/09 15:03:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}

Fixed::Fixed(const int N){
	std::cout << "Int constructor called\n";
	fixed_point = N << bits;
}

Fixed::Fixed(const float N){
	std::cout << "Float constructor called\n";
	fixed_point = roundf(N * (1 << bits));
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator =(const Fixed& src){
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		fixed_point = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return fixed_point;
}

void Fixed::setRawBits(int const raw){
	fixed_point = raw;
}

float Fixed::toFloat(void) const{
	return ((float)fixed_point / (1 << bits));
}

int Fixed::toInt(void) const{
	return (fixed_point >> bits);
}

std::ostream& operator <<(std::ostream &out, const Fixed& src){
	return out << src.toFloat();
}
