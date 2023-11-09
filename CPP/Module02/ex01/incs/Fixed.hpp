/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/09 13:42:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed();
	Fixed(const int N);
	Fixed(const float N);
	Fixed(const Fixed& obj);
	~Fixed();

	Fixed& operator=(const Fixed& src);

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