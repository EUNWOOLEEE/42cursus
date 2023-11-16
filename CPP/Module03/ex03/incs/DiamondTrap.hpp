/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:51:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 17:21:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{

public:
	DiamondTrap(void);
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap(void);

	DiamondTrap& operator =(const DiamondTrap& src);

	void _attack(DiamondTrap& target);

	void whoAmI();
	
private:
	std::string name;

};
