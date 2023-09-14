/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:00:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 12:50:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	public:
		void announce(void);

		Zombie(std::string name);
		~Zombie(void);

	private:
		std::string zombie_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif