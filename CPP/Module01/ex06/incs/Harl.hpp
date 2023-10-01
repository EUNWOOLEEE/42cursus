/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:00:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 11:10:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define USAGE_MSG "Usage: ./harlFilter [LEVEL]\n"
# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n"
# define INFO_MSG "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n"
# define WARNING_MSG "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n"
# define ERROR_MSG "This is unacceptable, I want to speak to the manager now.\n"
# define OTHER_MSG "[ Probably complaining about insignificant problems ]\n"

class Harl{

	public:
		Harl();
		
		void		complain(std::string level);

	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		
		void		(Harl::*func[4])(void);
};

#endif