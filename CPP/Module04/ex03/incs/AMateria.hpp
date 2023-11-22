/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:04:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 20:42:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
# define AMATERIA

# include <iostream>
# include "../incs/ICharacter.hpp"

class ICharacter;

class AMateria{

public:
	AMateria(void);
	AMateria(const AMateria& obj);
	AMateria(std::string const & _type);
	virtual ~AMateria(void);

	AMateria& operator =(const AMateria& obj);

	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;

};

#endif