/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:38:03 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/18 01:01:17 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidCharacter(char c) {

	if (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ')
		return true;
	else
		return false;
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