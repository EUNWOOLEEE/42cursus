/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:00:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 08:17:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int main(){
	int	N = 5;
	Zombie *horde = zombieHorde(N, "name");

	for(int i = 0; i < N; i++)
		horde[i].announce();

	delete horde;
	return 0;
}