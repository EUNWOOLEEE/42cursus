/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:40:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 17:16:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

class FragTrap : virtual public ClapTrap{

public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& obj);
	~FragTrap();

	FragTrap& operator =(const FragTrap& src);

	void attack(const std::string& target);
	void _attack(FragTrap& target);

	void highFivesGuys(void);

};
