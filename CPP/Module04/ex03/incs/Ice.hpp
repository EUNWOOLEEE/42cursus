/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:17:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 18:15:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "../incs/AMateria.hpp"

class Ice : public AMateria{

public:
	Ice(void);
	Ice(const Ice& obj);
	~Ice(void);

	Ice& operator =(const Ice& obj);

	AMateria* clone() const;

};

#endif