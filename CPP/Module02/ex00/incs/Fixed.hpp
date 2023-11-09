/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/09 15:02:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();

	Fixed& operator =(const Fixed& src);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					fix;
	static const int	bits;

};

#endif