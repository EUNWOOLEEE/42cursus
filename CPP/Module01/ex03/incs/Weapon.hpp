/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/21 18:01:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
	public:
		Weapon(std::string str);
		~Weapon(void);

		const std::string&	getType();
		void				setType(std::string newType);

	private:
		std::string type;
};

#endif