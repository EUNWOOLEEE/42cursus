/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:33:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 20:05:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "../incs/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& obj);
	~MateriaSource();
	
	MateriaSource& operator =(const MateriaSource& obj);
	
	const AMateria *getSlot(int idx) const;

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

private:
	AMateria			**slot;
	int					slotCnt;
	static const int	slotMax;

};

#endif