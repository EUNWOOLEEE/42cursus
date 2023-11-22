/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/22 21:02:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/Ice.hpp"
# include "../incs/Cure.hpp"
# include "../incs/Character.hpp"
# include "../incs/MateriaSource.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	std::cout << "\n";

	src->learnMateria(new Ice());
	std::cout << "\n";
	
	src->learnMateria(new Cure());
	std::cout << "\n";

	// std::cout << "-----Attempt equip with overlaped materia type-----\n";
	// std::cout << "\n";
	// src->learnMateria(new Cure());
	// std::cout << "\n";

	ICharacter* me = new Character("me");
	std::cout << "\n";

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
	std::cout << "\n";

    tmp = src->createMateria("cure");
    me->equip(tmp);
	std::cout << "\n";


	// std::cout << "-----------------Check deep copy-----------------\n";
	// ICharacter* meTmp = new Character(*(const Character *)me);
	// std::cout << "\n";
	// std::cout << meTmp << " " << me << "\n";
	// std::cout << meTmp->getSlot(0) << " " << me->getSlot(0) << "\n\n";


	// std::cout << "-----Attempt equip with same address materia-----\n";
	// me->equip(tmp);
	// std::cout << "\n";


	// std::cout << "--------Attempt equip materias more than 4-------\n";
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
	// std::cout << "\n";

    // tmp = src->createMateria("cure");
    // me->equip(tmp);
	// std::cout << "\n";

    // tmp = src->createMateria("cure");
    // me->equip(tmp);
	// std::cout << "\n";


	ICharacter* bob = new Character("bob");
	std::cout << "\n";


	me->use(0, *bob);
    me->use(1, *bob);
	std::cout << "\n";
	

	// std::cout << "---------------Use none equip slot---------------\n";
    // me->use(2, *bob);
	// std::cout << "\n";


	// std::cout << "------------------Test Unequip------------------\n";
	// const AMateria* slotTmp;
	// std::cout << "[before]\n";
	// for(int i = 0; i < 2; i++){
	// 	slotTmp = me->getSlot(i);
	// 	std::cout << "address: " << slotTmp << ", value: ";
	// 	if(slotTmp)
	// 		std::cout << slotTmp->getType() << "\n";
	// }

	// std::cout << "\n[delete]\n";
	// slotTmp = me->getSlot(0);
	// std::cout << "address: " << slotTmp << ", value: " << slotTmp->getType() << "\n";
	// me->unequip(0);
	// delete(slotTmp);

	// std::cout << "\n[after]\n";
	// for(int i = 0; i < 2; i++){
	// 	slotTmp = me->getSlot(i);
	// 	std::cout << "address: " << slotTmp << ", value: ";
	// 	if(slotTmp)
	// 		std::cout << slotTmp->getType() << "\n";
	// }
	// std::cout << "\n\n";


	delete bob;
	delete me;
	delete src;
	
	// system("leaks interface");

	return 0;
}