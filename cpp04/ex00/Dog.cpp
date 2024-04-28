/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 05:51:14 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal() {
		
	std::cout << "Default constructor for Dog called" << std::endl;
}

// Copy constructor
Dog::Dog(Dog const & to_copy) : Animal(to_copy) {

	std::cout << "Copy constructor for Dog called" << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Dog::~Dog () {

	std::cout << "Destructor for Dog called" << std::endl;
}

// Copy assignment Operator overload
Dog& Dog::operator=(Dog const & src) {

	std::cout << "Copy assignment operator for Dog called" << std::endl;

	if (this != &src) {
		Animal::operator=(src);
	}
	return *this;
}

// Dog implementation of the virtual method.
void Dog::setType() {

	this->type = "Dog";
}

std::string Dog::getType() {

	return this->type;
}

// Dog implementation of the virtual method.
void Dog::makeSound() {

	std::cout << "Woof! Woof!!! Baaaark" << std::endl;
}