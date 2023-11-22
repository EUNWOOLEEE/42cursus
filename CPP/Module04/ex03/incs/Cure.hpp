/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:17:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 17:19:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "../incs/AMateria.hpp"

class Cure : public AMateria{

public:
	Cure(void);
	Cure(const Cure& obj);
	~Cure(void);

	Cure& operator =(const Cure& obj);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif