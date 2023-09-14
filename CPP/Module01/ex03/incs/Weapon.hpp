/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 18:15:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon{
	public:
		Weapon(void);
		Weapon(std::string str);
		~Weapon(void);

		const std::string&	getType();
		void				setType(std::string newType);

	private:
		std::string type;
};

#endif