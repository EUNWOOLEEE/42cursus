/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:26:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/20 18:40:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

# include <iostream>
# include <fstream>

class Sed{

	public:
		Sed(char *file_name, char *copy_file_name);

	private:
		std::ifstream file;
		std::ofstream copy_file;
	
};

#endif