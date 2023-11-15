/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/15 19:02:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap{

public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();

	ClapTrap& operator =(const ClapTrap& src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void _attack(ClapTrap& target);

	void set_name(const std::string _name);
	void set_hp(const int _hp);
	void set_ep(const int _ep);
	void set_ad(const int _ad);

	std::string get_name(void) const;
	int get_hp(void) const;
	int get_ep(void) const;
	int get_ad(void) const;

private:
	std::string	name;
	int			hp;
	int			ep;
	int			ad;

};
