/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:03:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 20:09:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	integerPart = 0;
	fractionalPart = 0;
}

Fixed::Fixed(int n){
	std::cout << "Int constructor called\n";
	fix = n; //고정 소수점 값으로 변환
}

Fixed::Fixed(float n){
	std::cout << "Float constructor called\n";
	fix = n; //고정 소수점 값으로 변환
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	fix = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		fix = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return fix;
}

void Fixed::setRawBits(int const raw){
	fix = raw;
}

float Fixed::toFloat(void) const{
	// fixed-point 값을 부동 소수점 값으로 변환하는 멤버 함수
}

int Fixed::toInt(void) const{
	// fixed-point 값을 정수 값으로 변환하는 멤버 함수
}
