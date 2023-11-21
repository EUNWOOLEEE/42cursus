/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:04:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/21 16:09:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
# define AMATERIA

# include <iostream>

class AMateria{

public:
	AMateria(void);
	AMateria(const AMateria& obj);
	AMateria(std::string const & type);
	virtual ~AMateria(void);

	AMateria& operator =(const AMateria& obj);

	std::string const & getType() const; //Returns the materia type
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;

};

#endif