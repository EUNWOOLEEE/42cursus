/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:53 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 12:51:27 by eunwolee         ###   ########.fr       */
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

protected:
	std::string type;
	
};

#endif