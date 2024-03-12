#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm& operator =(const RobotomyRequestForm& obj);

		void execute(Bureaucrat const& executor) const;

	private :
		RobotomyRequestForm(void);
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& src);

#endif