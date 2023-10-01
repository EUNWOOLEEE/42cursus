/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:03:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 11:00:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(std::string name){
	_name = name;
}

Zombie::~Zombie(void){
	std::cout << "destroy " << _name << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << \
		": BraiiiiiiinnnzzzZ..." << std::endl;
}