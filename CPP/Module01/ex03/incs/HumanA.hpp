/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/21 18:01:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string s, Weapon& w);
		~HumanA(void);

		void attack(void);

	private:
		std::string	name;
		Weapon&		weapon;
};

#endif