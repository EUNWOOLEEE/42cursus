#include "../incs/RPN.hpp"

RPN::RPN(char* _expression) : expression(_expression), ss(expression) {
	std::cout << "[OCCF] RPN constructor called\n";
}

RPN::~RPN(void) {
	std::cout << "[OCCF] RPN destructor called\n";
}

std::string RPN::getNextToken(void) {
	std::string	token;

	std::getline(ss, token, ' ');
	return token;
}

bool RPN::isOperator(std::string& token) {
	if (token == "+"	\
		|| token == "-"	\
		|| token == "/"	\
		|| token == "*")
		return true;
	return false;
}

void RPN::pushToStack(std::string& token) {
	if (nstack.size() == 2	\
		|| token.size() != 1	\
		|| isdigit(token[0]) == false)
		throw std::invalid_argument("Invalid expression");

	int	n = atoi(token.c_str());

	if (n < 0 || 9 < n)
		throw std::invalid_argument("Nbers must be between 0 and 9");

	nstack.push(n);
}

void RPN::calculate(char operator_type) {
	if (nstack.size() != 2)
		throw std::invalid_argument("Invalid expression");

	int n1 = nstack.top();
	nstack.pop();
	int n2 = nstack.top();
	nstack.pop();

	if (operator_type == '+')
		nstack.push(n2 + n1);
	else if (operator_type == '-')
		nstack.push(n2 - n1);
	else if (operator_type == '/') {
		if (n1 == 0 || n2 == 0)
			throw std::runtime_error("Division by zero");
		nstack.push(n2 / n1);
	}
	else if (operator_type == '*')
		nstack.push(n2 * n1);
}

void RPN::printResult(void) const {
	if (nstack.size() != 1)
		throw std::invalid_argument("Invalid expression");
	
	std::cout << nstack.top() << "\n";
}
