/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:06:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 14:11:04 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void run_tests() {
	
	std::cout << static_cast<int>('a') << std::endl;
	
	ScalarConverter::convert("0"); // Valid character
	ScalarConverter::convert("70"); // Valid character
	ScalarConverter::convert("a"); // Valid character
	ScalarConverter::convert("\\"); // Non-displayable character
	ScalarConverter::convert("hello"); // Invalid: more than one character
	ScalarConverter::convert("");   // Invalid: empty string
	ScalarConverter::convert("34.12253");   // Invalid: empty string
	ScalarConverter::convert("45.235f");   // Invalid: empty string
	ScalarConverter::convert("0.42F");   // Invalid: empty string
	ScalarConverter::convert("0.12412");   // Invalid: empty string
	ScalarConverter::convert("%");   // Invalid: empty string
	ScalarConverter::convert("^35");   // Invalid: empty string
	ScalarConverter::convert("..34");   // Invalid: empty string
	ScalarConverter::convert("");   // Invalid: empty string
	ScalarConverter::convert("0.00f");   // Invalid: empty string
	
	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("          TEST 1️⃣ : CHARS         ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;

	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("          TEST 2️⃣ : INTEGERS         ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;
	

	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("          TEST 3️⃣ : FLOATS       ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;
	

	// std::cout << CYAN("\n--------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("          TEST 4️⃣ : DOUBLES       ")) << std::endl;
	// std::cout << CYAN("--------------------------------------") << std::endl;
	
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