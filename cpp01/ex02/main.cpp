/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:56:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 00:27:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define GREEN(text) "\033[32m" << text << "\033[0m"
#define BLUE(text) "\033[34m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"

int main() {

	//Initializations:
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	std::cout << std::endl;

	//Printing of the memory addresses:
	std::cout << "Memory address of the " << GREEN("string variable") << ": " << &str << std::endl;
	std::cout << "Memory address held by " << BLUE("stringPTR") << ": " << stringPTR << std::endl;
	std::cout << "Memory address held by " << RED("stringREF") << ": " << &stringREF << std::endl;
	std::cout << std::endl;
	
	//Printing of the values:
	std::cout << "Value of the " << GREEN("string variable") << ": " << str << std::endl;
	std::cout << "Value pointed to by " << BLUE("stringPTR") << ": " << *stringPTR << std::endl;
	std::cout << "Value pointed to by " << RED("stringREF") << ": " << stringREF << std::endl;
	std::cout << std::endl;
	
	return 0;
}