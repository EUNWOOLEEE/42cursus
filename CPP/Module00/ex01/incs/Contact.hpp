/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:04:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/14 12:50:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{

public:
	std::string get_info(int i);
	void		add_info(void);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;
	std::string info_arr[5];
};

#endif