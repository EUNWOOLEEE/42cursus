/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 16:06:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& obj){
	std::cout << "Brain copy constructor called\n";
	*this = obj;
}

Brain::~Brain(void){
	std::cout << "Brain destructor constructor called\n";
}

Brain& Brain::operator =(const Brain& obj){
	std::cout << "Brain copy assignment operator called\n";
	if(this != &obj)
		for(int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	return *this;
}

const std::string& Brain::getIdea(int idx){
	return ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea){
	ideas[idx] = idea;
}