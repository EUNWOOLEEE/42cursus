/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:53 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 18:08:42 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "../incs/WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

public:
	WrongCat(void);
	WrongCat(const WrongCat& obj);
	~WrongCat(void);
	
	WrongCat& operator =(const WrongCat& obj);

	void makeSound(void) const;
	
};

#endif