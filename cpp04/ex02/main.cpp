/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:30:39 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 07:18:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	// Initialization of all three types:
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	//! Shouldn't be possible, since AAnimal is an Abstract Class:
	// const AAnimal* c = new AAnimal();
	// AAnimal test;
	
	// testing the inherited getType member function:
	std::cout << std::endl;
	std::cout << "Object a is of type: " << UNDERLINE(dog->getType()) << std::endl;
	std::cout << "Object b is of type: " << UNDERLINE(cat->getType()) << std::endl;
	std::cout << std::endl;
	
	// testing the overriden makeSound method:
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete cat;
	delete dog;
	
	return 0;
}