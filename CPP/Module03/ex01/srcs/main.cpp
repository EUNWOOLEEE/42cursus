/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 01:04:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

int main(){
	ScavTrap a("a");

	std::cout << "\n";
	
	a.attack("target1");
	std::cout << "\n";
	
	a.attack("target2");
	std::cout << "\n";

	a.takeDamage(50);
	std::cout << "\n";
	
	a.beRepaired(30);
	std::cout << "\n";

	a.takeDamage(90);
	std::cout << "\n";
	
	a.beRepaired(30);
	std::cout << "\n";

	a.guardGate();
	std::cout << "\n";
	
	return 0;
}