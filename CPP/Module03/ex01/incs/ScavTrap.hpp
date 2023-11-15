/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:54:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();

	ScavTrap& operator =(const ScavTrap& src);

	void guardGate();

};