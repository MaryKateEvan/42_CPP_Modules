/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/02 16:05:02 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(ScalarConverter const & to_copy) {
	
	//no attributes to be copied, so nothing to be done here
	(void)to_copy;
}

// Destructor
ScalarConverter::~ScalarConverter () {}

// Copy assignment Operator overload
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & src) {

	// no attributes to be assigned
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string& input) {
	
	// 1st scenario: input is one character:
	if (input.size() == 1 && std::isprint(input[0]))
		std::cout << "char: '" << input[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}