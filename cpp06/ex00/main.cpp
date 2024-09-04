/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:06:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 17:15:44 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color

static void waitForEnter() {
	std::cout << DARK_GREY("Press " << BOLD("Enter")) << DARK_GREY(" to move to next category...");
	std::cin.get();  // Waits for the user to press Enter
}

static void run_tests() {
	
	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("       CATEGORY 1️⃣ : INPUT IS A CHAR    ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"a\"")) << std::endl;
	ScalarConverter::convert("a");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\" \"")) << std::endl;
	ScalarConverter::convert(" ");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"*\"")) << std::endl;
	ScalarConverter::convert("*");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"\"\"")) << std::endl;
	ScalarConverter::convert("\"");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"\\\"")) << std::endl;
	ScalarConverter::convert("\\");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"}\"")) << std::endl;
	ScalarConverter::convert("}");
	waitForEnter();

	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     CATEGORY 2️⃣ : INPUT IS AN INTEGER     ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"42\"")) << std::endl;
	ScalarConverter::convert("42"); // Valid character
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"65\"")) << std::endl;
	ScalarConverter::convert("65"); // Valid character
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"0\"")) << std::endl;
	ScalarConverter::convert("0"); // Non-displayable character
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"10\"")) << std::endl;
	ScalarConverter::convert("10"); // Non-displayable character
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-2147483648\"")) << std::endl;
	ScalarConverter::convert("-2147483648"); // INT_MIN
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"2147483647\"")) << std::endl;
	ScalarConverter::convert("2147483647"); // INT_MAX
	waitForEnter();

	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      CATEGORY 3️⃣ : INPUT IS A FLOAT    ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"42.0f\"")) << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"3.14f\"")) << std::endl;
	ScalarConverter::convert("3.14f");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"0.00001f\"")) << std::endl;
	ScalarConverter::convert("0.00001f");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-2345678.25f\"")) << std::endl;
	ScalarConverter::convert("-2345678.25f");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-2147483649.1\"")) << std::endl;
	ScalarConverter::convert("-2147483649.1"); // INT_MIN
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"2147483648.7\"")) << std::endl;
	ScalarConverter::convert("2147483648.7"); // INT_MAX
	waitForEnter();

	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      CATEGORY 4️⃣ : INPUT IS A DOUBLE    ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"42.042\"")) << std::endl;
	ScalarConverter::convert("42.042");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-65.352\"")) << std::endl;
	ScalarConverter::convert("-65.352");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"214748364901354\"")) << std::endl;
	ScalarConverter::convert("214748364901354"); //bigger than INT_MAX
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-1234567893456\"")) << std::endl;
	ScalarConverter::convert("-1234567893456"); //smaller than INT_MIN
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"0.0001\"")) << std::endl;
	ScalarConverter::convert("0.0001");
	waitForEnter();

	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("  CATEGORY 5️⃣ : INPUT IS PSEUDO LITERAL  ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	// float pseudo literals:
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"nanf\"")) << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"+inff\"")) << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-inff\"")) << std::endl;
	ScalarConverter::convert("-inff");
	// double pseudo literal:
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"nan\"")) << std::endl;
	ScalarConverter::convert("nan");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"+inf\"")) << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-inf\"")) << std::endl;
	ScalarConverter::convert("-inf");
	waitForEnter();

	std::cout << CYAN("\n-------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      CATEGORY 6️⃣ : INPUT IS INVALID    ")) << std::endl;
	std::cout << CYAN("-------------------------------------------") << std::endl;
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"hello world\"")) << std::endl;
	ScalarConverter::convert("hello world");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"\"")) << std::endl;
	ScalarConverter::convert("");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"^35\"")) << std::endl;
	ScalarConverter::convert("^35");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"..34\"")) << std::endl;
	ScalarConverter::convert("..34");
	std::cout << UNDERLINE("Output for: ./convert " << BOLD("\"-+21\"")) << std::endl;
	ScalarConverter::convert("-+21");
}

int main(int argc, char **argv) {
	
	// ScalarConverter converter; //this must not be possible, cause the class is not instanciable
	
	if (argc == 1)
		run_tests();
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << RED("Error: ") << "Only one argument is accepted." << std::endl;
	return 0;
}