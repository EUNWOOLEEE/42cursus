/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 14:42:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# include "../incs/Brain.hpp"

class Animal{

public:
	Animal(void);
	Animal(const Animal& obj);
	virtual ~Animal(void);
	
	Animal& operator =(const Animal& obj);

	virtual void makeSound(void) const;
	virtual std::string getType(void) const;

protected:
	std::string type;
	
};

#endif