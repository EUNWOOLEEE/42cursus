/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:45:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 15:56:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv){
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		for(int i=1; argv[i]; i++)
			for(int j=0; argv[i][j]; j++)
				argv[i][j] = toupper(argv[i][j]);
		for(int i=1; argv[i]; i++)
			std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}