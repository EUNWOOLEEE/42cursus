/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 17:53:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

int main(){
	DiamondTrap a("a");
	DiamondTrap b("b");

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

	a.whoAmI();
	b.whoAmI();
	std::cout << "\n";

	return 0;
}