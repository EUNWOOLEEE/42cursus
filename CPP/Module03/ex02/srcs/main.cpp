/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 01:06:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

int main(){
	FragTrap a("a");

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

	a.highFivesGuys();
	std::cout << "\n";
	
	return 0;
}