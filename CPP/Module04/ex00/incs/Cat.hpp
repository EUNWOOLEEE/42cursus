/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:53 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 17:48:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../incs/Animal.hpp"

class Cat : public Animal{

public:
	Cat(void);
	Cat(const Cat& obj);
	~Cat(void);
	
	Cat& operator =(const Cat& obj);

	void makeSound(void) const;
	
	std::string getType(void) const;

};

#endif