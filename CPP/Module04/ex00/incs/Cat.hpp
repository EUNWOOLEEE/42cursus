/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:53 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

# include "../incs/Animal.hpp"

class Cat : public Animal{

public:
	Cat(void);
	Cat(const Cat& obj);
	~Cat(void);
	
	Cat& operator =(const Cat& obj);

	void makeSound(void) const;

protected:
	std::string type;
	
};

#endif