/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/24 00:11:51 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>  // for rand()
#include <ctime> //for the time()
#include <list>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define GREEN(text) "\033[32m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

int main() {

	std::cout << CYAN("\n--------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("             A) THE TEST FROM THE SUBJECT:     ")) << std::endl;
	std::cout << CYAN("--------------------------------------------------------") << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << CYAN("\n--------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("                  B) ADDITIONAL TESTS:     ")) << std::endl;
	std::cout << CYAN("--------------------------------------------------------") << std::endl;
	{
		// creation of a list with 11.000 random integers:
		srand(time(NULL));
		std::list<int> nums_list(14999);
		for (std::list<int>::iterator it = nums_list.begin(); it != nums_list.end(); ++it) {
			*it = rand();
		}
		/******************************************************************************************************/
		std::cout << BOLD(CYAN("\n1️⃣  Enough space in Span to fill in the numbers ✅:")) << std::endl;
		Span sp1 = Span(15000); //instantiation of a Span with 15.000 maximum Capacity"
		//fill-in the Span with the 11.000 numbers from the nums_list:
		sp1.addNumsFromRange(nums_list.begin(), nums_list.end());
		// add also one more number manually to test the `addNumber`:
		sp1.addNumber(42);
		// sp1.printNumbers(); //you can uncomment this if you wanna see the numbers of the array
		std::cout << "\nSpan carries " << sp1.getSize() << " integer numbers" << std::endl;
		std::cout << BOLD("Shortest span") << " is: " << sp1.shortestSpan() << std::endl;
		std::cout << BOLD("Longest span") << " is: " << sp1.longestSpan() << std::endl;
		/******************************************************************************************************/
		try {
			std::cout << BOLD(CYAN("\n2️⃣  Not enough space in Span to fill in the numbers 🚫:")) << std::endl;
			Span sp2 = Span(500);
			sp2.addNumsFromRange(nums_list.begin(), nums_list.end());
		}
		catch (const std::exception& e) {
			std::cerr << RED("   ❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
		}
		/******************************************************************************************************/
		try {
			std::cout << BOLD(CYAN("\n3️⃣  Only one number in the span ❌:")) << std::endl;
			Span sp3 = Span(5);
			sp3.addNumber(-42);
			std::cout << sp3.shortestSpan() << std::endl;
			std::cout << sp3.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << RED("   ❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}