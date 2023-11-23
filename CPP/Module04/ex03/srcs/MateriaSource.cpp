/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:39:52 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/23 14:22:47 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

const int MateriaSource::slotMax = 4;

MateriaSource::MateriaSource(void) \
				: slot(new AMateria*[slotMax]), slotCnt(0){
	std::cout << "MateriaSource default constructor called\n";
	for(int i = 0; i < slotMax; i++)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj) \
				: slot(new AMateria*[slotMax]), slotCnt(0){
	std::cout << "MateriaSource copy constructor called\n";
	*this = obj;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called\n";
	for(int i = 0; i < slotCnt; i++)
		delete(slot[i]);
	delete[](slot);
}

MateriaSource& MateriaSource::operator =(const MateriaSource& obj){
	std::cout << "MateriaSource copy assignment operator called\n";
	if(this != &obj){
		for(int i = 0; i < slotCnt; i++) delete(slot[i]);
		delete[](slot);
		
		slotCnt = obj.slotCnt;
		
		slot = new AMateria*[slotMax];
		for(int i = 0; i < slotCnt; i++)
			slot[i] = obj.slot[i]->clone();
	}
	return *this;
}

const AMateria *MateriaSource::getSlot(int idx) const{
	return slot[idx];
}

void MateriaSource::learnMateria(AMateria* m){
	if(slotCnt == slotMax){
		std::cout << "Error: Slot is full\n";
		delete(m);
		return ;
	}
	else{
		for(int i = 0; i < slotCnt; i++){
			if(slot[i]->getType() == m->getType()){
				std::cout << "Error: Already learned materia\n";
				delete(m);
				return ;
			}
		}
		std::cout << "Save a " << m->getType() \
					<< " at slot[" << slotCnt << "]\n";
		slot[slotCnt++] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < slotCnt; i++)
		if(slot[i]->getType() == type)
			return (slot[i]->clone());
	return (NULL);
}
