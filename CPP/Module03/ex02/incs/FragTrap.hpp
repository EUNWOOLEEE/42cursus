/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:40:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 15:12:09 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "../incs/ScavTrap.hpp"

class FragTrap : public ClapTrap{

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

#endif