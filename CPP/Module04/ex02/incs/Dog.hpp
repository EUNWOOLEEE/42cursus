/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 15:34:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../incs/Animal.hpp"

class Dog : public Animal{

public:
	Dog(void);
	Dog(const Dog& obj);
	~Dog(void);
	
	Dog& operator =(const Dog& obj);

	void makeSound(void) const;

	std::string getType(void) const;
	Brain* getBrain(void);

protected:
	std::string type;
	
private:
	Brain* brain;
	
};

#endif