/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 17:17:46 by mevangel         ###   ########.fr       */
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

void ScalarConverter::inputIsFloat(const float& num_float) {

	int char_num = static_cast<int>(num_float);
	char c = static_cast<char>(num_float);
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
	if (num_float > INT_MAX || num_float < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << char_num << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(6) << num_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(10) << static_cast<double>(num_float) << std::endl;
}

void ScalarConverter::inputIsDouble(const double& num_double) {

	int char_num = static_cast<int>(num_double);
	char c = static_cast<char>(num_double);
	// 1. character out of char range:
	if (char_num < std::numeric_limits<char>::min() || char_num > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	// 2. Non displayable character:
	else if (std::isprint(c) == false)
		std::cout << "char: Non displayable" << std::endl;
	// 3. valid, printable characters:
	else
		std::cout << "char: '" << c << "'" << std::endl;

	// check for int overflow:
	if (num_double > INT_MAX || num_double < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << char_num << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(6) << static_cast<float>(num_double) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(10) << num_double << std::endl;

}

void ScalarConverter::inputIsPseudo(const std::string& arg, bool is_float) {
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (is_float) {
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << arg.substr(0, arg.size() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
	}
}

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
	// if ((arg.find('.') != std::string::npos) && (parse_string >> num_double) && parse_string.eof())
	if ((parse_string >> num_double) && parse_string.eof() && ((num_double < INT_MIN || num_double > INT_MAX) 
		|| ((arg.find('.') != std::string::npos))))
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

	std::string type = findType(arg);
	// std::cout << "Type for the string \"" << arg << "\" is: " << type << std::endl;
	
	if (type == "char")
		inputIsChar(arg[0]);
	else if (type == "int")
		inputIsInt(std::stoi(arg));
	else if (type == "float")
		inputIsFloat(std::stof(arg));
	else if (type == "double")
		inputIsDouble(std::stod(arg));
	else if (type == "pseudo_float")
		inputIsPseudo(arg, true);
	else if (type == "pseudo_double")
		inputIsPseudo(arg, false);
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

