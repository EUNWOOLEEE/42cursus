/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:11:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

int main(){
	ClapTrap a("a");
	ClapTrap b("b");

	std::cout << "\n";
	
	for(int i = 11; i; i--){
		a._attack(b);
		std::cout << "\n";
	}
	
	b.beRepaired(5);
	std::cout << "\n";
	
	return 0;
}