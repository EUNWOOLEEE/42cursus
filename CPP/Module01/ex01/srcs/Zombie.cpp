/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:03:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 08:30:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::~Zombie(void){
	std::cout << "destroy " << zombie_name << std::endl;
}

void Zombie::announce(void){
	std::cout << zombie_name << \
		": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name){
	zombie_name = name;
}