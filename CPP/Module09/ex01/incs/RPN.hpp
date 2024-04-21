#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <stack>

class RPN {
	public:
		RPN(char* _expression);
		~RPN(void);

		std::string	getNextToken(void);
		bool		isOperator(std::string& token);
		void		pushToStack(std::string& token);
		void		calculate(char operator_type);
		void		printResult(void) const;

	private:
		RPN(void);
		RPN(const RPN& obj);

		RPN& operator= (const RPN& obj);

		const std::string	expression;
		std::stringstream	ss;
		std::stack<int>		nstack;
};

#endif