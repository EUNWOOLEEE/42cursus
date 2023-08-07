/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:45:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/08/07 09:33:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;
};

class phonebook
{
	public:
		contact contact[8];
		int	cur;
		int cnt;
};

void pb_add(phonebook *pb);
void pb_search(phonebook pb);
int pb_exit(phonebook *pb);

#endif