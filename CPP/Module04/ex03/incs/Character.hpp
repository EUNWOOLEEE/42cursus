/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/21 16:11:42 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "../incs/AMateria.hpp"

class Character : public ICharacter{

public:
	Character(void);
	Character(const Character& obj);
	Character(std::string const & type);
	~Character(void);

	Character& operator =(const Character& obj);
	
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string name;
	AMateria slot[4];

};

#endif