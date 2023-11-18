/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 00:57:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

int main(){
	ClapTrap a("a");

	std::cout << "\n";
	
	a.attack("target");
	std::cout << "\n";

	a.takeDamage(5);
	std::cout << "\n";
	
	a.beRepaired(3);
	std::cout << "\n";
	
	return 0;
}