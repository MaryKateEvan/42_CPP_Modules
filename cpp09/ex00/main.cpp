/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykate <marykate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:32:14 by marykate          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:50 by marykate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	
	if (argc != 2) {
		std::cout << RED("❌ Error: ") << "expected a file as argument." << std::endl;
		std::cout << "✔️ Correct usage: " << BOLD("./btc <input_file_name>") << std::endl;
		return 0;
	}
	bitcoinExchanger(argv[1]);
	return 0;
}
	
	// std::cout << CYAN("\n------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("     TEST 1️⃣ : Easyfind on VECTOR container     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------") << std::endl;

	// std::vector<int> numbers;

	// //filling-in the vector with 4 random numbers:
	// numbers.push_back(0);
	// numbers.push_back(21);
	// numbers.push_back(42);
	// numbers.push_back(84);

	// std::cout << UNDERLINE("\nVector holds the elements") << ": ";
	// // Iterate over the vector using a range-based for loop
	// for (int num : numbers) { //this is C++11 condition
	// 	std::cout << num << " ";
	// }
	// std::cout << std::endl;
	
	// try {
	// 	std::cout << "\n1) Searching number " BOLD("42") << " in the vector: " << std::endl;
	// 	std::vector<int>::iterator search = easyfind(numbers, 42);
	// 	std::cout << GREEN("Found, at index " << std::distance(numbers.begin(), search)) << std::endl;

	// 	std::cout << "\n2) Searching number " BOLD("100") << " in the vector: " << std::endl;
	// 	std::vector<int>::iterator search2 = easyfind(numbers, 100);
	// 	std::cout << GREEN("Found, at index " << std::distance(numbers.begin(), search2)) << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	// }

	// std::cout << CYAN("\n------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("      TEST 2️⃣ : Easyfind on LIST container     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------") << std::endl;

	// std::list<int> nums_list;

	// //filling-in the list with 4 random numbers:
	// nums_list.push_back(15);
	// nums_list.push_back(25);
	// nums_list.push_back(-10);
	// nums_list.push_back(20);

	// std::cout << UNDERLINE("\nList holds the elements") << ": ";
	// // Iterate over the list using a range-based for loop
	// for (int num : nums_list) { //this is C++11 condition
	// 	std::cout << num << " ";
	// }
	// std::cout << std::endl;
	
	// try {
	// 	std::cout << "\n1) Searching number " BOLD("25") << " in the list: " << std::endl;
	// 	std::list<int>::iterator search = easyfind(nums_list, 25);
	// 	std::cout << GREEN("Found, at index " << std::distance(nums_list.begin(), search)) << std::endl;

	// 	std::cout << "\n2) Searching number " BOLD("10") << " in the list: " << std::endl;
	// 	std::list<int>::iterator search2 = easyfind(nums_list, 10);
	// 	std::cout << GREEN("Found, at index " << std::distance(nums_list.begin(), search2)) << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	// }
	// std::cout << std::endl;

// 	return 0;
// }