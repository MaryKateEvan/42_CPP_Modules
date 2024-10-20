/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:20:22 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/21 00:52:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {

	if (argc != 2) {
		std::cout << RED("❌ Error: expected an RPN expression.") << std::endl;
		std::cout << UNDERLINE("Example:") << BOLD(" ./RPN \"7 7 * 7 -\"") << std::endl;
		return 0;
	}

	try {
		RPN calculator;
		
		calculator.parseAndDoExpression(argv[1]);
		std::cout << GREEN("🏁 Result is: " << BOLD(calculator.getResult())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Error: " << UNDERLINE(e.what())) << std::endl;
	}

	return 0;
}
