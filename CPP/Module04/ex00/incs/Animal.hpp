/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 08:47:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal{

public:
	Animal(void);
	Animal(const Animal& obj);
	~Animal(void);
	
	Animal& operator =(const Animal& obj);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;

protected:
	std::string type;
	
};
