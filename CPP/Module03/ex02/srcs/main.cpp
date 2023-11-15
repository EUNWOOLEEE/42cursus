/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 20:58:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

int main(){
	FragTrap a("a");
	FragTrap b("b");

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

	return 0;
}