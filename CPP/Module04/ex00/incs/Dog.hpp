/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 08:46:50 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

class Dog : public Animal{

public:
	Dog(void);
	Dog(const Dog& obj);
	~Dog(void);
	
	Dog& operator =(const Dog& obj);

	void makeSound(void) const override;

protected:
	std::string type;
	
};
