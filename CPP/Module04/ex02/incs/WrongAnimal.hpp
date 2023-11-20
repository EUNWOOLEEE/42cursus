/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 18:03:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal(const std::string _type);
	~WrongAnimal(void);
	
	WrongAnimal& operator =(const WrongAnimal& obj);

	void makeSound(void) const;
	
	std::string getType(void) const;

protected:
	std::string type;
	
};

#endif