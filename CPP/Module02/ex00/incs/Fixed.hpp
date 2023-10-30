/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 20:13:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:
	Fixed();
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					fix;
	static const int	bit;

};

#endif