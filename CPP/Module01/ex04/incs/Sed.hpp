/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:26:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/24 16:02:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed{

	public:
		Sed(char *file_name, char* str1, char* str2);
		~Sed();
		
		void rewrite();

	private:
		std::ifstream	file;
		std::ofstream	copy_file;
		std::string		orignal_str;
		std::string		replace_str;
};

class Exception{

	public:
		Exception(const std::string& msg);
		const char* what() const;

	private:
		std::string msg_;
};

#endif
