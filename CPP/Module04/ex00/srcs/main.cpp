/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 14:44:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongCat.hpp"

int main() {
	std::cout << "TEST 1";
	std::cout << "\n---Create Animals---\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n------getType------\n";
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	std::cout << "\n-----makeSound-----\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();

	std::cout << "\n-------Delete-------\n";
	delete(i);
	delete(j);
	delete(meta);

	std::cout << "\n\nTEST 2";
	std::cout << "\n------WrongCat------\n";
	const WrongAnimal* w = new WrongCat();

	std::cout << "\n-----makeSound-----\n";
	w->makeSound();

	std::cout << "\n-------Delete-------\n";
	delete(w);
	return 0;
}