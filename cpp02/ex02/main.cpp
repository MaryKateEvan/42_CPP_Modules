/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:02:47 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 05:57:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

#define IN_GREEN(text) "\033[32m" << text << "\033[0m"
#define IN_RED(text) "\033[31m" << text << "\033[0m"
#define IN_YELLOW(text) "\033[33m" << text << "\033[0m"
#define IN_BLUE(text) "\033[34m" << text << "\033[0m"
#define IN_PURPLE(text) "\033[35m" << text << "\033[0m"
#define IN_CYAN(text) "\033[36m" << text << "\033[0m"

int main() {

	// THE TEST FROM THE SUBJECT PDF:
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	}

	// ADDITIONAL TESTS:
	{
	Fixed a(10.5f); 		// for integer constructor
	Fixed const b(2);		// for float constructor
	Fixed c(a);				// for copy constructor
	
	std::cout << std::endl;
	std::cout << UNDERLINE("Arithmetic operations on Fixed Objects:") << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << std::endl;
	std::cout << UNDERLINE("Comparison Operations on Fixed Objects:") << std::endl;
	std::cout << "a < b  is " << (a < b) << std::endl;
	std::cout << "a > b  is " << (a > b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;

	std::cout << std::endl;
	std::cout << UNDERLINE("Min/Max Overload Functions:") << std::endl;
	std::cout << "a = " << a << " and b = " << b << std::endl;
	std::cout << "The min from a and b is: " << Fixed::min(a, b) << std::endl;
	std::cout << "And the max from a and b is: " << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
	std::cout << UNDERLINE("Increment/Decrement operations on Fixed Objects") << std::endl;
	std::cout << "Object \"a\" initially is: " << a << std::endl;
	std::cout << "after ++a it becomes: " << ++a << std::endl;
	std::cout << "and after a++: " << a++ << std::endl;
	std::cout << std::endl;
	}

	return 0;
}
