/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 20:05:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "../incs/ICharacter.hpp"

class Character : public ICharacter{

public:
	Character(void);
	Character(const Character& obj);
	Character(std::string const & type);
	~Character(void);

	Character& operator =(const Character& obj);
	
	std::string const &getName() const;
	const AMateria *getSlot(int idx) const;
	
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string			name;
	AMateria			**slot;
	int					slotCnt;
	static const int	slotMax;
};

#endif