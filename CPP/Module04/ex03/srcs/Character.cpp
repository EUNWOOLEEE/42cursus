/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:05:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/23 14:39:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

const int Character::slotMax = 4;

Character::Character(void){
	std::cout << "Character default constructor called\n";
}

Character::Character(const Character& obj) \
			: name(obj.getName()), slot(new AMateria*[slotMax]), slotCnt(0){
	std::cout << "Character copy constructor called\n";
	*this = obj;
}

Character::Character(std::string const & _name) \
			: name(_name), slot(new AMateria*[slotMax]), slotCnt(0){
	std::cout << "Character constructor called\n";
	for(int i = 0; i < slotMax; i++)
		slot[i] = NULL;
}
    
Character::~Character(void){
	std::cout << "Character destructor called\n";
	for(int i = 0; i < slotCnt; i++)
		delete(slot[i]);
	delete[](slot);
}

Character& Character::operator =(const Character& obj){
	std::cout << "Character copy assignment operator called\n";
	if(this != &obj){
		name = obj.name;

		for(int i = 0; i < slotCnt; i++) delete(slot[i]);
		delete[](slot);

		slotCnt = obj.slotCnt;
		
		slot = new AMateria*[slotMax];
		for(int i = 0; i < slotCnt; i++)
			slot[i] = obj.slot[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const{
	return name;
}

const AMateria *Character::getSlot(int idx) const{
	return slot[idx];
}

void Character::equip(AMateria* m){
	if(slotCnt == slotMax){
		std::cout << "Error: Slot is full\n";
		delete(m);
		return ;
	}
	else{
		for(int i = 0; i < slotCnt; i++){
			if(slot[i] == m){
				std::cout << "Error: Already equiped materia\n";
				return ;
			}
		}
		std::cout << name << " equips a " << m->getType() \
					<< " at slot[" << slotCnt << "]\n";
		slot[slotCnt++] = m;
	}
}

void Character::unequip(int idx){
	if(slot[idx] == NULL)
		std::cout << "Error: Slot[" << idx << "] is empty\n";
	else{
		std::string tmp = slot[idx]->getType();
		for(int i = idx + 1; slot[i] != NULL; i++){
			slot[i - 1] = slot[i];
			slot[i] = NULL;
		}
		std::cout << name << " unequips a " << tmp \
					<< " in slot[" << idx << "]\n";
		slotCnt--;
	}
}

void Character::use(int idx, ICharacter& target){
	if(idx >= slotCnt)
		std::cout << "Error: Slot[" << idx << "] is empty\n";
	else
		slot[idx]->use(target);
}
