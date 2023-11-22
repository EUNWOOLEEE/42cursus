/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:28:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:29:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"

void checkBrain(const Animal* arr[]){
	const std::string *idea;
	
	std::cout << "\n-------Check copy depth!!-------\n";
	for(int i = 0; i < 2; i++){
		idea = &((Dog *)arr[i])->getBrain()->getIdea(0);
		std::cout << "Dog " << i << " : \"" << *idea << "\", addr : " << idea << "\n";
	}
	for(int i = 2; i < 4; i++){
		idea = &((Cat *)arr[i])->getBrain()->getIdea(0);
		std::cout << "Cat " << i << " : \"" << *idea << "\", addr : " << idea << "\n";
	}
	
	std::cout << "\n";
	Brain *dog = ((Dog *)arr[0])->getBrain();
	Brain *cat = ((Cat *)arr[2])->getBrain();

	std::cout << "Dog src value : \"" << dog->getIdea(0) << "\", addr : " << &(dog->getIdea(0)) << "\n";
	std::cout << "Cat dst value : \"" << cat->getIdea(0) << "\", addr : " << &(cat->getIdea(0)) << "\n";

	std::cout << "\n";
	dog->setIdea(0, "hi");
	*cat = *dog;

	std::cout << "\n";
	std::cout << "Dog src value : \"" << dog->getIdea(0) << "\", addr : " << &(dog->getIdea(0)) << "\n";
	std::cout << "Cat dst value : \"" << cat->getIdea(0) << "\", addr : " << &(cat->getIdea(0)) << "\n\n";

	*((Dog *)arr[1]) = *((Dog *)arr[0]);
	
	std::cout << "\n-------Check copy depth again!!-------\n";
	for(int i = 0; i < 2; i++){
		idea = &((Dog *)arr[i])->getBrain()->getIdea(0);
		std::cout << "Dog " << i << " : \"" << *idea << "\", addr : " << idea << "\n";
	}
	for(int i = 2; i < 4; i++){
		idea = &((Cat *)arr[i])->getBrain()->getIdea(0);
		std::cout << "Cat " << i << " : \"" << *idea << "\", addr : " << idea << "\n";
	}
	std::cout << "\n\n";
}

int main() {
	const Animal *arr[4];

	std::cout << "---Create 2 dogs and 2 cats---\n";
	for(int i = 0; i < 2; i++){
		arr[i] = new Dog();
	}
	for(int i = 2; i < 4; i++){
		arr[i] = new Cat();
		std::cout << std::endl;
	}
	
	for(int i = 0; i < 4; i++)
		arr[i]->makeSound();
	std::cout << std::endl;

	// checkBrain(arr);

	std::cout << "--------Delete animals--------\n";
	for(int i = 0; i < 4; i++){
		delete(arr[i]);
		std::cout << std::endl;
	}
	// system("leaks brain");
	return 0;
}