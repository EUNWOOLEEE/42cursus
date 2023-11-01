/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 20:09:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed();
	Fixed(int n);
	Fixed(float n);
	Fixed(const Fixed& obj);
	~Fixed();

	Fixed& operator=(const Fixed& src);
	// Fixed& operator<<(const Fixed& src); //출력 스트림 객체로 전달된 부동 소수점 표현을 삽입

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int					integerPart;
	int					fractionalPart;
	static const int	bit;

};

#endif