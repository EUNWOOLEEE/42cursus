/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:38:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/24 16:02:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Sed.hpp"

bool	check_error(int argc, char **argv){
	if(argc != 4){
		std::cout << "Usage: filename original_str replace_str\n";
		return true;
	}
	if(!argv[2][0] || !argv[3][0]){
		std::cout << "String must not be empty\n";
		return true;
	}
	return false;
}

int	main(int argc, char **argv){
	if(check_error(argc, argv) == true)
		return 0;

	try{
		Sed files(argv[1], argv[2], argv[3]);
		files.rewrite();
	} catch(Exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
