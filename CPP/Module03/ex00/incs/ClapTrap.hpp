/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/16 16:19:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap{

public:
	ClapTrap(void);
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap(void);

	ClapTrap& operator =(const ClapTrap& src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void _attack(ClapTrap& target);

private:
	std::string	name;
	int			hp;
	int			ep;
	int			ad;

};