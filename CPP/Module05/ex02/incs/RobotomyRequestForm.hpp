#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm& operator =(const RobotomyRequestForm& obj);

		void execute(Bureaucrat const& executor) const;

	private :
		RobotomyRequestForm(void);
};

#endif