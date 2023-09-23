/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/23 17:57:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

int main(){
	Harl harl = Harl();

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;
	
	harl.complain("WARNING");
	std::cout << std::endl;
	
	harl.complain("ERROR");
	std::cout << std::endl;
	
	return 0;
}