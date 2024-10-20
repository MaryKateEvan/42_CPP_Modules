/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:20:55 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 19:27:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream> // "string stream"
#include <stdexcept>
#include <limits>  // for INT_MAX
#include <algorithm>
#include <cctype> // for isdigit()
#include <cstdlib> // for std::stoi()
#include <stack>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
#define GRAY(text) "\033[90m" << text << "\033[0m"
#define GREEN(text) "\033[32m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

class RPN {
	
	private:
		
		std::stack<double> rpn_stack;		// double, cause the results of divisions might not be integers


	public:
		
		RPN();								// default constructor
		RPN(RPN const & to_copy);			// copy constructor
		~RPN();								// destructor
		RPN& operator=(RPN const & src);	// Assignment operator overload
		
		void parseExpression(std::string const & expr);

};

void calculateRPN(const char* input);