/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:03:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 07:26:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(std::string name){
	zombie_name = name;
}

Zombie::~Zombie(void){
	std::cout << "destroy " << zombie_name << std::endl;
}

void Zombie::announce(void){
	std::cout << zombie_name << \
		": BraiiiiiiinnnzzzZ..." << std::endl;
}