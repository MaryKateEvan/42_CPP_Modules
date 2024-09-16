/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:44:56 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/16 22:23:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define CYAN(text) "\033[1;96m" << text << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"

// 1. Function applicable on ints, floats, doubles
/**
 * @brief: template function to change a number to its power of 2. 
 * @param num: of typename num_type, so that the function is applicable to all:
 * 			   int, floats and doubles.
 */
template< typename num_type >
void power2(num_type & num) {
	num = num * num;
}

// 2. Function applicable on strings:

// void capitalizeStr(std::string & str) {
// 	for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
// 		*i = std::toupper(*i);
// 	}
// }

void capitalizeStr(std::string & str) {
	for (size_t i = 0; i != str.length(); ++i)
		str[i] = std::toupper(str[i]);
}

/**
 * @brief: template function to be able to print the content of an array, regardless
 * if that array contains strings or integers or doubles or anything else... 
 * @param array: the array whose elements we want to print
 * @param size: the amount of elements the array has.
 */
template<typename Type>
void printArrayElements(Type array, size_t size) {
	for (size_t i = 0; i != size; ++i) {
		std::cout << array[i];
		if (i != size - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
		
}

int main( void ) {

	std::cout << CYAN(BOLD("\nTest 1️⃣ : the `iter` on STRINGS")) << std::endl;
	std::cout << CYAN("-------------------------------") << std::endl;
	{
		std::string words[5] = {"Hello", "world", "@mk", "here", "wondering!"};
		std::cout << UNDERLINE("The array initially") << ": ";
		printArrayElements(words, 5);
		::iter(words, 5, capitalizeStr);
		std::cout << UNDERLINE("The array " << BOLD("after `iter`")) << ": ";
		printArrayElements(words, 5);
		std::cout << std::endl;
	}
	
	std::cout << CYAN(BOLD("\nTest 2️⃣ : the `iter` on INTS")) << std::endl;
	std::cout << CYAN("----------------------------") << std::endl;
	{
		int array[] = {1, -4, 10, 7, 42};
		std::cout << UNDERLINE("The array initially") << ": ";
		printArrayElements(array, 4);
		::iter(array, 4, power2<int>);
		std::cout << UNDERLINE("The array " << BOLD("after `iter`")) << ": ";
		printArrayElements(array, 4);
		std::cout << std::endl;
	}

 	// 1️⃣  TEST 2️⃣ TEST 3️⃣ TEST 4️⃣ TEST 5️⃣	
	
	return 0;
}
