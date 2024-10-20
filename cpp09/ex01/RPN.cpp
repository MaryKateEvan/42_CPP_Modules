/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:38:03 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/21 01:02:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// default constructor
RPN::RPN() {}

// Copy constructor
RPN::RPN(RPN const & to_copy) : rpn_stack(to_copy.rpn_stack) {}

// Copy assignment Operator overload
RPN& RPN::operator=(RPN const & src) {

	if (this != &src)
		this->rpn_stack = src.rpn_stack;
	return *this;
}

// Destructor
RPN::~RPN () {}

bool RPN::isAnOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::do_operation(double& num1, double& num2, char Operator) {
	
	double result;
	switch (Operator) {
		case '+': 
			result = num1 + num2;
			break ;
		case '-':
			result = num1 - num2;
			break ;
		case '*':
			result = num1 * num2;
			break ;
		case '/':
			if (num2 == 0)
				throw std::runtime_error("division with 0 not allowed");
			result = num1 / num2;
			break ;
		//this shouldnt be reached since im checking above for the operator characters, but just for readability reasons
		default: 
			throw std::invalid_argument("unknown operator");
	}
	this->rpn_stack.push(result); //puts the result on the stack so that it can be used for next operation
	// printStack(this->rpn_stack); //for debugging purposes
}

void RPN::parseAndDoExpression(std::string const & expr) {
	// 1. First we check if there are no numbers at all:
	if (expr.empty() || expr.find_first_not_of(" \t\n\r") == std::string::npos) //in case input is "   		  "
		throw std::invalid_argument("empty expression");
	// 2. check for different characters than the: \t\n\r0123456789+-*/
	for (char c : expr) {
		if (!(std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || std::isspace(static_cast<unsigned char>(c))))
			throw std::invalid_argument("invalid character(s) present");
	}
	bool expectingSpace = false;
	// 3. Parse the numbers and operators and execute the expression
	for (size_t i = 0; i < expr.size(); ++i) {
		if (expectingSpace && i != (expr.size() - 1) && (expr[i] != ' '))
			throw std::invalid_argument("invalid formatting");
		if (std::isdigit(static_cast<unsigned char>(expr[i]))) {
			rpn_stack.push(expr[i] - '0');
			expectingSpace = true;
		}
		else if (isAnOperator(expr[i])) {
			// if there are not 2 numbers on the stck, operation not possible:
			if (rpn_stack.size() < 2)
				throw std::invalid_argument("not enough numbers for operator \"" + std::string(1, expr[i]) + "\"");
			// but if we have the two numbers, then we can `pop` them from the stack and do the asked operation on them:
			double num2 = rpn_stack.top();
			rpn_stack.pop();
			double num1 = rpn_stack.top();
			rpn_stack.pop();
			do_operation(num1, num2, expr[i]);
			expectingSpace = true;
		}
		else if (std::isspace(static_cast<unsigned char>(expr[i])))
			expectingSpace = false;
		else if (expr[i] != ' ')
			throw std::invalid_argument("invalid character(s) present");
	}
	// at the end the stack must have only one element, the final result.
	if (rpn_stack.size() != 1)
		throw std::invalid_argument("invalid expression"); //if it doesn't have only one, it means there were not enough operators for the given numbers
}

double RPN::getResult() const {
	return (this->rpn_stack.top());
}

/* util, debugging function to print the content of the stack */
void RPN::printStack(std::stack<double> stack) {
	// Iterate (in a local copy, doesn't modify the original stack) while the stack is not empty
	while (!stack.empty()) {
		std::cout << stack.top() << " "; // Access the top element
		stack.pop(); // Remove the top element
	}
	std::cout << std::endl;
}