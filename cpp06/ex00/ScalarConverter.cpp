/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 05:35:14 by mevangel         ###   ########.fr       */
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

bool ScalarConverter::displayCharConversion(const std::string& arg) {
	
	int char_num = 0;
	if (arg.size() == 1 && !std::isdigit(arg[0]) && std::isprint(arg[0]))
		char_num = static_cast<int>(arg[0]);
	else {
		std::istringstream parse_string(arg); //a type of stream specifically used for reading from strings as if they were input streams, like reading from the console or a file.

		// here we try to "extract" an integer from the string stream:
		if (!(parse_string >> char_num) || !parse_string.eof()) {
			std::cout << "char: impossible" << std::endl;
			return false; //when an integer couldn't be extracted
		}
		//if we successfully extract the integer then we check the possibilities:
		// 1) out of the char range [-128,127]
		if (char_num < std::numeric_limits<char>::min() || char_num > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible" << std::endl;
			return false;
		}
		// 2) non-printable character:
		if (!std::isprint(char_num)) {
			std::cout << "char: Non displayable" << std::endl;
			return false;
		}
	}
	// 3) valid, printable character:
	std::cout << "char: '" << static_cast<char>(char_num) << "'" << std::endl;
	return true;
}

// bool ScalarConverter::handleInt(const std::string& arg) {
	
// }

// bool ScalarConverter::handleFloat(const std::string& arg) {
	
// }

// bool ScalarConverter::handleDouble(const std::string& arg) {
	
	
// }

void ScalarConverter::convert(const std::string& arg) {
	
	// if (arg.size() == 1 && std::isalpha(arg[0])) {
	// 	std::cout << "char: '" << arg[0] << "'" << std::endl;
	// 	std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
	// 	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(arg[0]) << "f" << std::endl;
	// 	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(arg[0]) << std::endl;
	// }
	// else
		displayCharConversion(arg);
	std::cout << std::endl;
	// 1st scenario: arg is one character:
	
}

