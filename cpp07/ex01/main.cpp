/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:44:56 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/16 23:18:10 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define CYAN(text) "\033[1;96m" << text << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"

// struct to store the coordinates of a point, in any type the user wants. 
// for example: int, float, double
template <typename Type>
struct coords {
	Type x;
	Type y;
	Type z;
};

// 1a. Function applicable on ints, floats, doubles
/**
 * @brief: template function to change a number to its power of 2. 
 * @param num: of typename num_type, so that the function is applicable to all:
 * 			   int, floats and doubles.
 */
template< typename num_type >
void power2(num_type & num) {
	num = num * num;
}

// 1b. Second function applicable on ints, floats, doubles
/**
 * @brief: template function to change a number to its division by 10. 
 * @param num: of typename num_type, so that the function is applicable to all:
 * 			   int, floats and doubles.
 */
template< typename num_type >
void divideWith10(num_type & num) {
	num = num / 10;
}

// 2. Function applicable on strings:
void capitalizeStr(std::string & str) {
	for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
		*i = std::toupper(*i);
	}
}
// // version 2:
// void capitalizeStr(std::string & str) {
// 	for (size_t i = 0; i != str.length(); ++i)
// 		str[i] = std::toupper(str[i]);
// }

// 3. Function applicable on a struct of coordinates:
template <typename Type>
void printCoordinates(coords<Type> point) {
	std::cout << "Point is in (x,y,z): (" << point.x << "," << point.y << "," << point.z << ")" << std::endl;
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

int main() {

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
		int array[5] = {1, -4, 10, 7, 42};
		std::cout << UNDERLINE("The array initially") << ": ";
		printArrayElements(array, 4);
		::iter(array, 4, power2<int>);
		std::cout << UNDERLINE("The array " << BOLD("after `iter`")) << ": ";
		printArrayElements(array, 4);
		std::cout << std::endl;
	}

	std::cout << CYAN(BOLD("\nTest 3️⃣ : the `iter` on FLOATS")) << std::endl;
	std::cout << CYAN("-------------------------------") << std::endl;
	{
		float array[4] = {42.0f, 5.0f, 1.25f, -4.2f};
		std::cout << UNDERLINE("The array initially") << ": ";
		printArrayElements(array, 4);
		::iter(array, 4, power2<float>);
		std::cout << UNDERLINE("The array " << BOLD("after `iter`")) << ": ";
		printArrayElements(array, 4);
		std::cout << std::endl;
	}

	std::cout << CYAN(BOLD("\nTest 4️⃣ : double `iter` on DOUBLES")) << std::endl;
	std::cout << CYAN("----------------------------------") << std::endl;
	{
		double array[4] = {42, 5, 1.25, -4.20};
		std::cout << UNDERLINE("The array initially") << ": ";
		printArrayElements(array, 4);
		//double iter call:
		::iter(array, 4, power2<double>);
		::iter(array, 4, divideWith10<double>);
		std::cout << UNDERLINE("The array " << BOLD("after `iter`")) << ": ";
		printArrayElements(array, 4);
		std::cout << std::endl;
	}

	std::cout << CYAN(BOLD("\nTest 5️⃣ : `iter` on STRUCTS")) << std::endl;
	std::cout << CYAN("----------------------------------") << std::endl;
	{
		coords<int> points[3] = {{0, 0, 0}, {42, 1, 21}, {-25, 11, 15}};
		::iter(points, 3, printCoordinates<int>);
		std::cout << std::endl;
	}

	return 0;
}
