/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:03:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/04 18:39:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}

Fixed::Fixed(int N){
	std::cout << "Int constructor called\n";
	fixed_point = N << bit;
}

Fixed::Fixed(float N){
	std::cout << "Float constructor called\n";
	fixed_point = N; //고정 소수점 값으로 변환
	// fixed_point = static_cast<int>(roundf(value * (1 << bit))))
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		fixed_point = src.getRawBits();
	return *this;
}

Fixed& Fixed::operator<<(const Fixed& src){
	//출력 스트림 객체로 전달된 부동 소수점 표현을 삽입
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return fixed_point;
}

void Fixed::setRawBits(int const raw){
	fixed_point = raw;
}

float Fixed::toFloat(void) const{
	// fixed-point 값을 부동 소수점 값으로 변환하는 멤버 함수
}

int Fixed::toInt(void) const{
	return (fixed_point >> bit);
}
