/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:20:22 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/17 23:49:04 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	
	if (argc != 2) {
		std::cout << RED("❌ Error: expected an RPN expression.") << std::endl;
		std::cout << UNDERLINE("Example:") << BOLD(" ./RPN \"7 7 * 7 -\"") << std::endl;
		return 0;
	}
	(void)argv;
	parseExpression(argv[1]);
	// calculateRPN(argv[1]);
	return 0;
}
