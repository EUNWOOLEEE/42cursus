/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 17:51:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

int main(){
	ScavTrap a("a");
	ScavTrap b("b");

	std::cout << "\n";
	
	for(int i = 3; i; i--){
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

	FragTrap c("c");
	FragTrap d("d");
	std::cout << "\n";
	
	for(int i = 3; i; i--){
		c._attack(d);
		std::cout << "\n";
	}
	
	d.beRepaired(20);
	std::cout << "\n";
	
	for(int i = 2; i; i--){
		c._attack(d);
		std::cout << "\n";
	}

	d.beRepaired(20);
	std::cout << "\n";

	c.highFivesGuys();
	std::cout << "\n";
	
	return 0;
}