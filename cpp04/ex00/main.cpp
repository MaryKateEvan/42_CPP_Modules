/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:30:39 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 07:38:34 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

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
	
	return 0;
}