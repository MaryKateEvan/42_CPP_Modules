/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 23:28:39 by mevangel         ###   ########.fr       */
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

// #define MAX_VAL 42

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
		std::list<int> nums_list(14000);
		for (std::list<int>::iterator it = nums_list.begin(); it != nums_list.end(); ++it) {
			*it = rand();
		}
		/******************************************************************************************************/
		std::cout << BOLD(CYAN("\n1️⃣  Enough space in Span to fill in the numbers ✅ :")) << std::endl;
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
			std::cout << BOLD(CYAN("\n2️⃣  Not enough space in Span to fill in the numbers ❌ :")) << std::endl;
			Span sp_small = Span(500);
			sp_small.addNumsFromRange(nums_list.begin(), nums_list.end());
		}
		catch (const std::exception& e) {
			std::cerr << RED("   ❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
		}
		/******************************************************************************************************/
		try {
			std::cout << BOLD(CYAN("\n3️⃣  Only one number in the span ⚠️ :")) << std::endl;
			Span sp2 = Span(5);
			sp2.addNumber(-42);
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << RED("   ❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
		}
		std::cout << std::endl;
	}
	
	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("             TEST 1️⃣ : Creation of Array objects     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;

	// std::cout << UNDERLINE("A) INT Array with randomized values:") << std::endl;
	// srand(time(NULL));
	// Array<int> int_nums(MAX_VAL);
	// for (int i = 0; i < MAX_VAL; ++i) {
	// 	int_nums[i] = rand() % 101;
	// }
	// printArray(int_nums);

	// std::cout << UNDERLINE("\nB) DOUBLE Array with randomized values:") << std::endl;
	// Array<double> double_nums(MAX_VAL);
	// for (int i = 0; i < MAX_VAL; ++i) {
	// 	double_nums[i] = (rand() % 20) * 0.6;
	// }
	// printArray(double_nums);

	// std::cout << UNDERLINE("\nC) STRING Array with random-selected words:") << std::endl;
	// Array<std::string> projects(4);
	// // Pool of predefined strings
	// std::string string_pool[] = {
	// 	"libft", "ft_printf", "Born2BeRoot", "gnl", "so_long", "push_swap", "philo", "minishell", "cpps"
	// };
	// for (int i = 0; i < 4; ++i) {
	// 	projects[i] = string_pool[rand() % 9];
	// }
	// printArray(projects);

	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("      TEST 2️⃣ : Assignment operator & Copy constructor     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;
	
	// Array<int> tmp = int_nums;
	// Array<int> test(tmp);
	// std::cout << UNDERLINE("Content of the `test` array:") << std::endl;
	// printArray(test);
	
	// // The change of the source array `int_nums` must not modify the test array:
	// for (int i = 0; i < MAX_VAL; ++i) {
	// 	int_nums[i] += 1;
	// }
	// std::cout << UNDERLINE("\nContent of the source `int_nums` array modified to:") << std::endl;
	// printArray(int_nums);
	// std::cout << UNDERLINE("`test` array must not be affected:") << std::endl;
	// printArray(test);

	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("         TEST 3️⃣ : Trying to access out of range:          ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;

	// try {
	// 	std::cout << "\n...trying to access invalid indexes:\n";
	// 	std::cout << double_nums[100] << std::endl;
	// 	std::cout << int_nums[42] << std::endl;
	// 	std::cout << "Success!" << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	// }
	// std::cout << std::endl;

	// // ------------------------------------------------------------------------------------------------
	// // Some edge cases that should work still and not throw error:
	// // ------------------------------------------------------------------------------------------------
	// // empty array creation:
	// Array<float> empty(0);
	// printArray(empty);
	// // and default constructor:
	// Array<std::string> something;
	// printArray(something);
	
	return 0;
}