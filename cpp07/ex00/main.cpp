/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:44:56 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/06 23:20:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#define CYAN(text) "\033[1;96m" << text << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"

int main( void ) {

	std::cout << CYAN("\n------------------------------------") << std::endl;
	std::cout << CYAN(BOLD(" 1) THE TEST FROM THE SUBJECT.PDF:     ")) << std::endl;
	std::cout << CYAN("------------------------------------") << std::endl;
	// std::cout << BOLD("1) THE TEST FROM THE SUBJECT.PDF: ") << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	}
	
	std::cout << CYAN("\n------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("       2) ADDITIONAL TESTS:     ")) << std::endl;
	std::cout << CYAN("------------------------------------") << std::endl;

	std::cout << UNDERLINE("A. Comparing floats:") << std::endl;
	{
		float a = 42.24f;
		float b = 21.12f;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	}
	std::cout << UNDERLINE("\nB. Comparing strings:") << std::endl;
	{
		std::string c = "world";
		std::string d = "Hello ";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	}
	std::cout << UNDERLINE("\nC. Equality:") << std::endl;
	{
		double a = 42.24;
		double b = 21.12 * 2;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
	}
	
	return 0;
}