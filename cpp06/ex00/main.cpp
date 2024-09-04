/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:06:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 15:31:00 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void run_tests() {
	

	// ScalarConverter::convert("a"); // Valid character
	// ScalarConverter::convert("\\"); // Non-displayable character

	// ScalarConverter::convert("34.12253");   // Invalid: empty string
	// ScalarConverter::convert("45.235f");   // Invalid: empty string
	// ScalarConverter::convert("0.42F");   // Invalid: empty string
	// ScalarConverter::convert("0.12412");   // Invalid: empty string
	// ScalarConverter::convert("%");   // Invalid: empty string

	// ScalarConverter::convert("");   // Invalid: empty string
	// ScalarConverter::convert("0.00f");   // Invalid: empty string
	// ScalarConverter::convert("-2147483648");   // INT_MIN
	// ScalarConverter::convert("2147483647");   // INT_MAX
	// ScalarConverter::convert("-2147483649");   // smaller than INT_MIN
	// ScalarConverter::convert("2147483649345678");   // smaller than INT_MIN
	
	std::cout << CYAN("\n--------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     CATEGORY 1️⃣ : INPUT IS A CHAR    ")) << std::endl;
	std::cout << CYAN("--------------------------------------") << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert(" ");
	ScalarConverter::convert("*");
	ScalarConverter::convert("\"");
	ScalarConverter::convert("\\");
	ScalarConverter::convert("}");

	std::cout << CYAN("\n--------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("    CATEGORY 2️⃣ : INPUT IS INTEGER     ")) << std::endl;
	std::cout << CYAN("--------------------------------------") << std::endl;
	ScalarConverter::convert("42"); // Valid character
	ScalarConverter::convert("65"); // Valid character
	ScalarConverter::convert("0"); // Non-displayable character
	ScalarConverter::convert("10"); // Non-displayable character
	ScalarConverter::convert("-2147483648"); // INT_MIN
	ScalarConverter::convert("2147483647"); // INT_MAX

	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("     CATEGORY 3️⃣ : INPUT IS FLOAT    ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;
	

	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("     CATEGORY 4️⃣ : INPUT IS DOUBLE    ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;
	
	std::cout << CYAN("\n--------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("    CATEGORY 5️⃣ : INPUT IS INVALID    ")) << std::endl;
	std::cout << CYAN("--------------------------------------") << std::endl;
	ScalarConverter::convert("hello");
	ScalarConverter::convert("");
	ScalarConverter::convert("^35");
	ScalarConverter::convert("..34");
	ScalarConverter::convert("-+21");
	
	
}

int main(int argc, char **argv) {
	
	if (argc == 1)
		run_tests();
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << RED("Error: ") << "Only one argument is accepted." << std::endl;
	
	return 0;
}