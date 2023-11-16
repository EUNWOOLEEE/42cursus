/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 16:37:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
	ScavTrap(void);
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap(void);

	ScavTrap& operator =(const ScavTrap& src);

	void attack(const std::string& target);
	void _attack(ScavTrap& target);

	void guardGate(void);

};