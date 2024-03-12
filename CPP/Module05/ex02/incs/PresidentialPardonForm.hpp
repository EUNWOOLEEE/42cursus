#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public :
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm& operator =(const PresidentialPardonForm& obj);

		void execute(Bureaucrat const& executor) const;

	private :
		PresidentialPardonForm(void);
};

#endif