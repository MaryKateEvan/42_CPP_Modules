/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:21:45 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 00:45:40 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define GREEN(text) "\033[32m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

int main() {
	
	std::cout << CYAN("\n------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     TEST 1️⃣ : Easyfind on VECTOR container     ")) << std::endl;
	std::cout << CYAN("------------------------------------------------") << std::endl;

	std::vector<int> numbers;

	//filling-in the vector with 4 random numbers:
	numbers.push_back(0);
	numbers.push_back(21);
	numbers.push_back(42);
	numbers.push_back(84);

	std::cout << UNDERLINE("\nVector holds the elements") << ": ";
	// Iterate over the vector using a range-based for loop
	for (int num : numbers) { //this is C++11 condition
		std::cout << num << " ";
	}
	std::cout << std::endl;
	
	try {
		std::cout << "\n1) Searching number " BOLD("42") << " in the vector: " << std::endl;
		std::vector<int>::iterator search = easyfind(numbers, 42);
		std::cout << GREEN("Found, at index " << std::distance(numbers.begin(), search)) << std::endl;

		std::cout << "\n2) Searching number " BOLD("100") << " in the vector: " << std::endl;
		std::vector<int>::iterator search2 = easyfind(numbers, 100);
		std::cout << GREEN("Found, at index " << std::distance(numbers.begin(), search2)) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}

	std::cout << CYAN("\n------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      TEST 2️⃣ : Easyfind on LIST container     ")) << std::endl;
	std::cout << CYAN("------------------------------------------------") << std::endl;

	std::list<int> nums_list;

	//filling-in the vector with 4 random numbers:
	nums_list.push_back(15);
	nums_list.push_back(25);
	nums_list.push_back(-10);
	nums_list.push_back(20);

	std::cout << UNDERLINE("\nList holds the elements") << ": ";
	// Iterate over the vector using a range-based for loop
	for (int num : nums_list) { //this is C++11 condition
		std::cout << num << " ";
	}
	std::cout << std::endl;
	
	try {
		std::cout << "\n1) Searching number " BOLD("25") << " in the vector: " << std::endl;
		std::list<int>::iterator search = easyfind(nums_list, 25);
		std::cout << GREEN("Found, at index " << std::distance(nums_list.begin(), search)) << std::endl;

		std::cout << "\n2) Searching number " BOLD("10") << " in the list: " << std::endl;
		std::list<int>::iterator search2 = easyfind(nums_list, 10);
		std::cout << GREEN("Found, at index " << std::distance(nums_list.begin(), search2)) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}

	
	// // Get the size of the list
	// std::cout << "Size of vector: " << nums_list.size() << std::endl;

	// // Remove the last element
	// numbers.pop_back();

	// std::cout << "After pop_back, size of vector: " << numbers.size() << std::endl;
	// std::cout << "Last element after pop_back: " << numbers.back() << std::endl;  // 20

	// try {
	// 	std::cout << numbers.at(5);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	// }
	// std::cout << std::endl;


	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("      TEST 2️⃣ : Easy find on LIST container     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;
	




	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("         TEST 3️⃣ : Trying to access out of range:          ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;

	try {

	}
	catch (const std::exception& e) {
		std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	std::cout << std::endl;

	
	return 0;
}