/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 17:49:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{

public:
	Animal(void);
	Animal(const Animal& obj);
	Animal(const std::string _type);
	virtual ~Animal(void);
	
	Animal& operator =(const Animal& obj);

	virtual void makeSound(void) const;
	
	std::string getType(void) const;

protected:
	std::string type;
	
};

#endif