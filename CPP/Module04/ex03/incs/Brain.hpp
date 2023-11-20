/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:59:50 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/20 15:50:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{

public:
	Brain(void);
	Brain(const Brain& obj);
	~Brain(void);
	
	Brain& operator =(const Brain& obj);

	const std::string& getIdea(int idx);
	void setIdea(int idx, const std::string &idea);

private:
	std::string ideas[100];

};

#endif