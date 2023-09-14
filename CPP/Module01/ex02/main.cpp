/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:22:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 11:34:42 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string		str = "HI THIS IS BRAIN";
	std::string*	strPTR = &str;
	std::string&	strREF = str;

	std::cout << "address" << std::endl << \
	"str: " << &str << std::endl << \
	"strPTR: " << strPTR << std::endl << \
	"strREF: " << &strREF << std::endl;

	std::cout << "value" << std::endl << \
	"str: " << str << std::endl << \
	"strPTR: " << *strPTR << std::endl << \
	"strREF: " << strREF << std::endl;

	return 0;
}