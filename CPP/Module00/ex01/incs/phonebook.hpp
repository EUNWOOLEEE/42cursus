/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:45:25 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:09 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class Phonebook{

private:
	Contact	contacts[8];

public:
	int		cur;
	int		cnt;
	Contact *get_contact(int i);
	void	pb_add(Phonebook *pb);
	void	pb_search(Phonebook pb);
	void	pb_exit(void);
};

#endif