/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 21:21:02 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>  // for rand()

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

#define MAX_VAL 42

/**
 * @brief: template function to be able to print the content of an array, regardless
 * if that array contains strings or integers or doubles or anything else... 
 * @param array: the array whose elements we want to print
 * @param size: the amount of elements the array has.
 */
template<typename T>
void printArray(T array) {
	for (unsigned int i = 0; i < array.size(); ++i) {
		std::cout << array[i];
		if (i != array.size() - 1)
			std::cout << ", ";
		if ((i > 0 && i % 11 == 0) || i == array.size() - 1)
			std::cout << std::endl;
	}
}

int main() {

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
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