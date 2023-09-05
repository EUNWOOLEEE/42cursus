/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:45:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/05 19:00:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;
		std::string info_arr[5];
	public:
		std::string get_info(int i){
			return info_arr[i];
		}
		void add_info(contact *info){
			std::cout << "First name: ";
			if (!(std::cin >> info->first_name))
				exit(0);
			info->info_arr[0] = info->first_name;
		
			std::cout << "Last name: ";
			if (!(std::cin >> info->last_name))
				exit(0);
			info->info_arr[1] = info->last_name;
			
			std::cout << "Nickname: ";
			if (!(std::cin >> info->nickname))
				exit(0);
			info->info_arr[2] = info->nickname;

			std::cout << "Phone number: ";
			if (!(std::cin >> info->number))
				exit(0);
			info->info_arr[3] = info->number;

			std::cout << "Darkest secret: ";
			if (!(std::cin >> info->secret))
				exit(0);
			info->info_arr[4] = info->secret;
		}
};

class phonebook
{
	private:
		contact contacts[8];
	public:
		int	cur;
		int cnt;
		contact *get_contact(int i){
			return &contacts[i];
		}
};

void pb_add(phonebook *pb);
void pb_search(phonebook pb);
int pb_exit(void);

#endif