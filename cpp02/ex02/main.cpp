/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:02:47 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 05:24:38 by mevangel         ###   ########.fr       */
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
	// ...from here
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
	// ...until here.

	// ADDITIONAL TESTS:
	{
	Fixed a(10.5f); 		// for integer constructor
	Fixed b(2);				// for float constructor
	Fixed c(a);				// for copy constructor
	
	Fixed sum(a + c);
	Fixed dif(a - b);
	Fixed mult(b * c);
	Fixed div(a / c);
	
	std::cout << std::endl;
	std::cout << UNDERLINE("Testing the arithmetic operations of the Fixed Objects:") << std::endl;
	std::cout << "The " << BOLD("sum") << " of objects a and c is " << sum << std::endl;
	std::cout << "The " << BOLD("difference") << " of object b from a is " << dif << std::endl;
	std::cout << "The product of the " BOLD("multiplication") << " of object b and c is " << mult << std::endl;
	std::cout << "The quotent of object a " << BOLD("divided") << " by c is " << div << std::endl;
	}

	return 0;
}
