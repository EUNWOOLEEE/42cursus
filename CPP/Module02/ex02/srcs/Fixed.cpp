/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:03:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/10 07:38:41 by eunwolee         ###   ########.fr       */
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

bool Fixed::operator >(const Fixed& arg) const {
	return (fixed_point > arg.fixed_point);
}

bool Fixed::operator <(const Fixed& arg) const {
	return (fixed_point < arg.fixed_point);
}

bool Fixed::operator >=(const Fixed& arg) const {
	return (fixed_point >= arg.fixed_point);
}

bool Fixed::operator <=(const Fixed& arg) const {
	return (fixed_point <= arg.fixed_point);
}

bool Fixed::operator ==(const Fixed& arg) const {
	return (fixed_point == arg.fixed_point);
}

bool Fixed::operator !=(const Fixed& arg) const {
	return (fixed_point != arg.fixed_point);
}

float Fixed::operator +(const Fixed& arg){
	return (toFloat() + arg.toFloat());
}

float Fixed::operator -(const Fixed& arg){
	return (toFloat() - arg.toFloat());
}

float Fixed::operator *(const Fixed& arg){
	return (toFloat() * arg.toFloat());
}

float Fixed::operator /(const Fixed& arg){
	if (arg.toFloat() == 0.0){
		std::cout << "Divider is 0" << std::endl;
		return 0;
	}
	return (toFloat() / arg.toFloat());
}

Fixed& Fixed::operator ++(){
	fixed_point++;
	return (*this);
}

Fixed& Fixed::operator --(){
	fixed_point--;
	return (*this);
}

const Fixed Fixed::operator ++(int){
	Fixed temp = *this;
	++(*this);
	return temp;
}

const Fixed Fixed::operator --(int){
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed& arg1, Fixed& arg2){
	return (arg1.fixed_point <= arg2.fixed_point ? arg1 : arg2);
}

const Fixed& Fixed::min(const Fixed& arg1, const Fixed& arg2){
	return (arg1.fixed_point <= arg2.fixed_point ? arg1 : arg2);
}

Fixed& Fixed::max(Fixed& arg1, Fixed& arg2){
	return (arg1.fixed_point >= arg2.fixed_point ? arg1 : arg2);
}

const Fixed& Fixed::max(const Fixed& arg1, const Fixed& arg2){
	return (arg1.fixed_point >= arg2.fixed_point ? arg1 : arg2);
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
