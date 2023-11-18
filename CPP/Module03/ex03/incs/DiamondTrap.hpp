/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:51:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 01:15:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "../incs/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{

public:
	DiamondTrap(void);
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap(void);

	DiamondTrap& operator =(const DiamondTrap& src);

	void attack(const std::string& target);

	void whoAmI();
	
private:
	std::string name;

};

#endif