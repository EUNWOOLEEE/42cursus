/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/21 18:01:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string s);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon& w);

	private:
		std::string	name;
		Weapon*		weapon;
};

#endif