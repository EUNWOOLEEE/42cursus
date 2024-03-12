#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

# define shrub_trees				\
  "          *                \n"	\
  "         /|\\              \n"	\
  "        /*|O\\             \n"	\
  "       /*/|\\*\\           \n"	\
  "      /X/O|*\\X\\          \n"	\
  "     /*/X/|\\X\\*\\        \n"	\
  "    /O/*/X|*\\O\\X\\       \n"	\
  "   /*/O/X/|\\X\\O\\*\\     \n"	\
  "  /X/O/*/X|*\\O\\X\\*\\    \n"	\
  " /O/X/*/O/|\\X\\*\\O\\X\\  \n"	\
  "/O/X/*/O/X|O\\X\\O\\X\\*\\ \n"	\
  "         |X|               \n"	\
  "         |X|               \n"	\
  "         |X|               \n"	\
  "     ____|X|____           \n";

class ShrubberyCreationForm : public AForm {
	public :
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator =(const ShrubberyCreationForm& obj);

		void			execute(Bureaucrat const& executor) const;
		static AForm*	makeInstance(const std::string& name);

	private :
		ShrubberyCreationForm(void);
};

#endif