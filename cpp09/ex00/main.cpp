/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:04:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/21 01:32:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	
	if (argc != 2) {
		std::cout << RED("❌ Error: expected a file as argument.") << std::endl;
		std::cout << "✔️ Correct usage: " << BOLD("./btc <input_file_name>") << std::endl;
		return 0;
	}
	BitcoinExchange count;
	count.CalculateExchange(argv[1]);
	return 0;
}
