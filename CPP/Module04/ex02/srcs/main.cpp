/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:29:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"

int main() {
	std::cout << "---Create dog and cat---\n";
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();

	std::cout << dog->getType() << "\n";
	dog->makeSound();
	std::cout << cat->getType() << "\n";
	cat->makeSound();
	std::cout << std::endl;
	
	std::cout << "--------Delete animals--------\n";
	delete(dog);
	delete(cat);

	// system("leaks abstract");
	return 0;
}