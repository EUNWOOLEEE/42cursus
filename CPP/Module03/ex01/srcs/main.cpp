/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 19:14:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

int main(){
	ScavTrap a("a");
	ScavTrap b("b");

	std::cout << "\n";
	
	for(int i = 4; i; i--){
		a._attack(b);
		std::cout << "\n";
	}
	
	b.beRepaired(20);
	std::cout << "\n";
	
	for(int i = 2; i; i--){
		a._attack(b);
		std::cout << "\n";
	}

	b.beRepaired(20);
	std::cout << "\n";

	a._attack(b);
	std::cout << "\n";
	
	return 0;
}