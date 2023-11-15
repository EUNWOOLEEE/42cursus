/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 20:43:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{

public:
	Fixed(void);
	Fixed(const int N);
	Fixed(const float N);
	Fixed(const Fixed& obj);
	~Fixed(void);

	Fixed& operator =(const Fixed& src);
	bool operator >(const Fixed& arg);
	bool operator <(const Fixed& arg);
	bool operator >=(const Fixed& arg);
	bool operator <=(const Fixed& arg);
	bool operator ==(const Fixed& arg);
	bool operator !=(const Fixed& arg);

	float operator +(const Fixed& arg);
	float operator -(const Fixed& arg);
	float operator *(const Fixed& arg);
	float operator /(const Fixed& arg);
	
	Fixed& operator ++(void);
	Fixed& operator --(void);
	const Fixed operator ++(int);
	const Fixed operator --(int);

	static Fixed& min(Fixed& arg1, Fixed& arg2);
	static const Fixed& min(const Fixed& arg1, const Fixed& arg2);
	static Fixed& max(Fixed& arg1, Fixed& arg2);
	static const Fixed& max(const Fixed& arg1, const Fixed& arg2);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int					fixed_point;
	static const int	bits;
	
};

std::ostream& operator<<(std::ostream &out, const Fixed& src);

#endif