/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/23 18:25:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << USAGE_MSG;
		return 0;
	}
		
	Harl harl = Harl();
	harl.complain((std::string)argv[1]);
	
	return 0;
}