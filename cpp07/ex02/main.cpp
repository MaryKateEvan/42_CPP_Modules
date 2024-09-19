/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:51:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/19 21:43:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
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
	
	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("             TEST 1️⃣ : Creation of Array objects     ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;

	std::cout << UNDERLINE("1. Default Initializations:") << std::endl;

	Array<int> IntArray(5);
	std::cout << "Created an " << BOLD("INT Array") << " of size: " << IntArray.size() << std::endl;
	std::cout << "The content of this default-initialized int array is: " << std::endl;
	printArray(IntArray);
	std::cout << std::endl;

	Array<std::string> StringsArray(5);
	std::cout << "Created a " << BOLD("STRINGS Array") << " of size: " << StringsArray.size() << std::endl;
	std::cout << "The content of this default-initialized strings array is: " << std::endl;
	printArray(StringsArray);

	std::cout << UNDERLINE("\n2. Create and Fill-in an Int Array with Random values:") << std::endl;
	srand(time(NULL));
	Array<int> random_nums(MAX_VAL);
	for (int i = 0; i < MAX_VAL; ++i) {
		random_nums[i] = rand() % 101;
	}
	printArray(random_nums);

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      TEST 2️⃣ : Assignment operator & Copy constructor              ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	
	Array<int> tmp = random_nums;
	Array<int> test(tmp);
	std::cout << UNDERLINE("Content of the test array:") << std::endl;
	printArray(test);
	
	// The change of the source array `random_nums` must not modify the test array:
	for (int i = 0; i < MAX_VAL; ++i) {
		random_nums[i] += 1;
	}
	std::cout << UNDERLINE("\nContent of the random_nums array modified to:") << std::endl;
	printArray(random_nums);
	std::cout << UNDERLINE("Test array must not be affected:") << std::endl;
	printArray(test);

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("         TEST 3️⃣ : Trying to access out of range:          ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	
	Array<double> double_nums(MAX_VAL);
	for (int i = 0; i < MAX_VAL; ++i) {
		double_nums[i] = (rand() % 20) * 0.6;
	}
	std::cout << UNDERLINE("Content of the double_nums array, of size 42:") << std::endl;
	printArray(double_nums);
	
	try {
		std::cout << "\n...trying to access invalid indexes:\n";
		std::cout << double_nums[100] << std::endl;
		std::cout << random_nums[42] << std::endl;
		std::cout << StringsArray[10] << std::endl;
		std::cout << "Success!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}