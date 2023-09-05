/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:44:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/05 20:15:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	phonebook pb = phonebook();
	std::string cmd;
	
	while (true)
	{
		std::cout << "Enter a command [ADD][SEARCH][EXIT]" << std::endl;
		if (!(std::cin >> cmd))
			exit(0);
		
		if (cmd == "ADD")
			pb_add(&pb);
		else if (cmd == "SEARCH")
			pb_search(pb);
		else if (cmd == "EXIT")
			return (pb_exit());
	}
		return (0);
}