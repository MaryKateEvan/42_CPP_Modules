/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:38:03 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 19:02:37 by mevangel         ###   ########.fr       */
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

// bool isValidCharacter(char c) {

// 	return (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || std::isspace(c));
// }

void RPN::parseExpression(std::string const & expr) {
	// 1. First we check if there are no numbers at all:
	if (expr.empty() || expr.find_first_not_of(" \t\n\r") == std::string::npos) //in case input is "   		  "
		throw std::invalid_argument("empty expression");
	// 2. check for different characters than the: \t\n\r0123456789+-*/
	for (char c : expr) {
		if (!(std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || std::isspace(c)))
			throw std::invalid_argument("invalid character in the expression");
			
	}

	
}







// bool parseExpression(std::string const & expr) {
// 	int numbers = 0;
// 	int operators = 0;
// 	bool expectNumber = true;

// 	for (size_t i = 0; i < expr.size(); ++i) {
// 		char current = expr[i];

// 		// Check for valid characters
// 		if (!isValidCharacter(current)) {
// 			std::cout << "❌ Error: Invalid character found: " << current << std::endl;
// 			return false;
// 		}

// 		// If expecting a number
// 		if (expectNumber) {
// 			if (std::isdigit(current)) {
// 				numbers++;
// 				expectNumber = false; // Next we expect an operator or a space
// 			} else if (current != ' ') {
// 				std::cout << "❌ Error: Expected a number at position " << i << std::endl;
// 				return false;
// 			}
// 		} 
// 		// If expecting an operator or space
// 		else {
// 			if (current == '+' || current == '-' || current == '*' || current == '/') {
// 				operators++;
// 				expectNumber = true; // Next we expect a number
// 			} else if (current == ' ') {
// 				continue;
// 			} else {
// 				std::cout << "❌ Error: Unexpected character at position " << i << std::endl;
// 				return false;
// 			}
// 		}
// 	}

// 	// Check if there are enough operators
// 	if (numbers <= operators) {
// 		std::cout << "❌ Error: Too few numbers or too many operators." << std::endl;
// 		return false;
// 	}

	// return true;
// }