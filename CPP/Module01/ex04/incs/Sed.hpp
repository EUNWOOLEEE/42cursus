/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:26:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/15 20:34:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed{

	public:
		Sed(char *file_name, char* s1, char* s2);
		~Sed();
		
		void rewrite();
		void rewrite_nl();

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
