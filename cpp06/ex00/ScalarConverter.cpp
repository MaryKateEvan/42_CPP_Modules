/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 14:57:24 by mevangel         ###   ########.fr       */
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

void ScalarConverter::inputIsChar(const char& c) {
	
	int char_num = static_cast<int>(c);

	// 1. character out of char range:
	if (char_num < std::numeric_limits<char>::min() || char_num > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	// 2. Non displayable character:
	else if (std::isprint(c) == false)
		std::cout << "char: Non displayable" << std::endl;
	// 3. valid, printable characters:
	else
		std::cout << "char: '" << c << "'" << std::endl;

	// printing of the rest numberic types:
	std::cout << "int: " << char_num << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(char_num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(char_num) << std::endl;
}

void ScalarConverter::inputIsInt(const int& num_int) {

	// 1. character out of char range:
	if (num_int < std::numeric_limits<char>::min() || num_int > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	// 2. Non displayable character:
	else if (std::isprint(num_int) == false)
		std::cout << "char: Non displayable" << std::endl;
	// 3. valid, printable characters:
	else
		std::cout << "char: '" << static_cast<char>(num_int) << "'" << std::endl;
	
	// printing of the rest numberic types:
	std::cout << "int: " << num_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num_int) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num_int) << std::endl;

	
}

// void ScalarConverter::inputIsFloat(const std::string& arg) {
	
// }

// void ScalarConverter::inputIsDouble(const std::string& arg) {
	
// }

// void ScalarConverter::inputIsPseudo(const std::string& arg, bool is_float) {
	
// }

std::string ScalarConverter::findType(std::string arg) {
	
	// if (arg.size() == 1 && !std::isdigit(arg[0]) && std::isprint(arg[0]))
	if (arg.size() == 1 && !std::isdigit(arg[0]))
		return "char";
	if (arg == "nanf" || arg == "-inff" || arg == "+inff")
		return "pseudo_float";
	if (arg == "nan" || arg == "-inf" || arg == "+inf")
		return "pseudo_double";

	std::istringstream parse_string(arg);
	// 1) parsing a double:
	double num_double = 0;
	if ((parse_string >> num_double) && parse_string.eof())
		return "double";
	// 2) parsing an integer:
	parse_string.clear();
	parse_string.str(arg);
	int num_int = 0;
	if ((parse_string >> num_int) && parse_string.eof())
		return "int";
	// 3) parsing a float:
	parse_string.clear();//to clear from the above parsing for double operation
	if (arg[arg.size() - 1] == 'f' || arg[arg.size() - 1] == 'F')
	{
		parse_string.str(arg.substr(0, arg.size() - 1));
		float num_float = 0;
		if ((parse_string >> num_float) && parse_string.eof())
			return "float";
	}
	return "invalid_string";
}

void ScalarConverter::convert(const std::string& arg) {
	
	// if (arg.size() == 1 && std::isalpha(arg[0])) {
	// 	std::cout << "char: '" << arg[0] << "'" << std::endl;
	// 	std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
	// 	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(arg[0]) << "f" << std::endl;
	// 	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(arg[0]) << std::endl;
	// }

          
	std::string type = findType(arg);
	std::cout << "Type for the string \"" << arg << "\" is: " << type << std::endl;
	
	if (type == "char")
		inputIsChar(arg[0]);
	else if (type == "int")
		inputIsInt(std::stoi(arg));
	std::cout << std::endl;
	//1st scenario: arg is one character:
	
}

