/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 18:35:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string s);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon w);

	private:
		Weapon&		weapon;
		std::string	name;
};

#endif