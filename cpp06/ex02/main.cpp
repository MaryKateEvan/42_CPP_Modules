/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:52:19 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 20:37:44 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "InheritingClasses.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

#define IN_GREEN(text) "\033[32m" << text << "\033[0m"
#define IN_RED(text) "\033[31m" << text << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"

// It randomly instanciates A, B or C class and returns the instance as a Base pointer.
Base* generate(void) {
	
	int classID = rand() % 3;

	if (classID == 0)
		return new A;
	else if (classID == 1)
		return new B;
	else
		return new C;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p) {
	if (dynamic_cast<A*>(p)) //which means if the cast returns a valid pointer and not null
		std::cout << "This object is of class: " << BOLD("A") << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This object is of class: " << BOLD("B") << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This object is of class: " << BOLD("C") << std::endl;
	else
		std::cout << "This object doesn't belong to any of the A, B, C classes." << std::endl;
}

// It prints the actual type of the object carried by the reference `p`: "A", "B" or "C".
void identify(Base& p) {
	//check for Class A:
	try {
		(void) dynamic_cast<A&>(p); //void casue i dont really need the cacsted value-reference. I just want to see if the cast is possible
		std::cout << "This object is of class: " << BOLD("A") << std::endl;
		return ;
	}
	catch (std::exception& e) {
		//check for Class B:
		try {
			(void) dynamic_cast<B&>(p); //void casue i dont really need the cacsted value-reference. I just want to see if the cast is possible
			std::cout << "This object is of class: " << BOLD("B") << std::endl;
		}
		catch (std::exception& e) {
			//check for Class C:
			try {
				(void) dynamic_cast<C&>(p); //void casue i dont really need the cacsted value-reference. I just want to see if the cast is possible
				std::cout << "This object is of class: " << BOLD("C") << std::endl;
				return ;
			}
			catch (std::exception& e) {
				std::cout << "This object does not belong to any of the A, B, C classes." << std::endl;
			}
		}
	}
}

int main() {

	srand(time(NULL)); // sets the seed for rand() using the current time (in seconds), to ensure the seed and randominsing is diferrent every time the program runs

	// Random generation of 3 objects:
	Base* ptr1 = generate();
	Base* ptr2 = generate();
	Base* ptr3 = generate();

	Base& ref1 = *ptr1;
	Base& ref2 = *ptr2;
	Base& ref3 = *ptr3;

	Base* invalid = NULL;

	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	std::cout << std::endl;
	identify(ref1);
	identify(ref2);
	identify(ref3);
	std::cout << std::endl;
	identify(invalid);
	
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}