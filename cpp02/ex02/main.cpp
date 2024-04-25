/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:02:47 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 20:59:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

int main() {

	// THE TEST FROM THE SUBJECT PDF:
	std::cout << BOLD("\nPART A: SUBJECT'S PDF TEST\n") << std::endl;
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
	std::cout << BOLD("\nPART B: ADDITIONAL TESTS\n") << std::endl;
	{
	Fixed a(10.5f); 		// for integer constructor
	Fixed const b(2);		// for float constructor
	
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
