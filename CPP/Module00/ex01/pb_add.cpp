/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:29:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/08 12:36:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void pb_add(phonebook *pb)
{
	int idx = pb->cur;
	contact *info = pb->get_contact(idx);
	
	info->add_info();

	(*pb).cur = ((*pb).cur + 1) % 8;
	if ((*pb).cnt < 8) (*pb).cnt++;
}
