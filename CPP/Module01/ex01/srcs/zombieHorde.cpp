/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:03:51 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 08:53:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name){
	Zombie *horde = new Zombie[N]();

	for(int i = 0; i < N; i++)
		horde[i].set_name(name);

	return &horde[0];
}