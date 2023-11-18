/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:00:03 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/19 01:00:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

public:
	ClapTrap(void);
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap(void);

	ClapTrap& operator =(const ClapTrap& src);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string	name;
	int			hp;
	int			ep;
	int			ad;

};

#endif