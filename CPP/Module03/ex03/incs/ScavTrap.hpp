/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:14:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 15:11:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "../incs/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

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

#endif