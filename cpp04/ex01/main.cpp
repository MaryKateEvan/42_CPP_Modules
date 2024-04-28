/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:30:39 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 17:52:08 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	// PART A: CORRECT BEHAVIOR
	std::cout << BOLD_UNDERLINE("\n1. TESTING THE SUBTYPE POLYMORPHISM\n") << std::endl;
	{
	// Initialization of all three types:
	const Animal* a = new Animal();
	const Animal* b = new Dog();
	const Animal* c = new Cat();
	
	// testing the inherited getType member function:
	std::cout << std::endl;
	std::cout << "Object a is of type: " << UNDERLINE(a->getType()) << std::endl;
	std::cout << "Object b is of type: " << UNDERLINE(b->getType()) << std::endl;
	std::cout << "Object c is of type: " << UNDERLINE(c->getType()) << std::endl;
	std::cout << std::endl;
	
	// testing the overriden makeSound method:
	a->makeSound();
	b->makeSound();
	c->makeSound();
	std::cout << std::endl;

	delete c;
	delete b;
	delete a;
	}

	// PART B: WRONG BEHAVIOR
	{
	std::cout << BOLD_UNDERLINE("\n2. TESTING THE BRAIN 🧠 OF OUR PETS\n") << std::endl;
	// Initialization of all three types:


	}
	
	return 0;
}