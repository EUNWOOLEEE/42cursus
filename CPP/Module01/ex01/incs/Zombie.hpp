/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:00:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	public:
		~Zombie(void);

		void announce(void);
		void set_name(std::string name);

	private:
		std::string zombie_name;
};

Zombie*	zombieHorde(int N, std::string name);
	
#endif