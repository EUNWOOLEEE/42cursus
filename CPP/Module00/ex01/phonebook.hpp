/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:45:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/10 20:00:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact{

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
	void		add_info(void);
};

class phonebook{

private:
	contact	contacts[8];

public:
	int		cur;
	int		cnt;
	contact *get_contact(int i){
		return &contacts[i];
	}
	void	pb_add(phonebook *pb);
	void	pb_search(phonebook pb);
	void	pb_exit(void);
};

#endif