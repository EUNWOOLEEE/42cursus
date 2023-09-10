/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:50:28 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/10 19:02:46 by eunwolee         ###   ########.fr       */
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
	return (0);
}
