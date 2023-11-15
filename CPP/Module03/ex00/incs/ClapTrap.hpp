/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/14 20:25:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap{

public:
	ClapTrap();
	ClapTrap(std::string _name, int _hp, int _ep, int ad);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();

	ClapTrap& operator =(const ClapTrap& src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string name;
	int			hp;
	int			ep;
	int			ad;

};