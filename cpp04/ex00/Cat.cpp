/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 06:07:52 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal() {
		
	std::cout << "Default constructor for Cat called" << std::endl;
	this->setType();
}

// Copy constructor
Cat::Cat(Cat const & to_copy) : Animal(to_copy) {

	std::cout << "Copy constructor for Cat called" << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Cat::~Cat () {

	std::cout << "Destructor for Cat called" << std::endl;
}

// Copy assignment Operator overload
Cat& Cat::operator=(Cat const & src) {

	std::cout << "Copy assignment operator for Cat called" << std::endl;

	if (this != &src) {
		Animal::operator=(src);
	}
	return *this;
}

// Cat implementation of the virtual method.
void Cat::setType() {

	this->type = "Cat";
}

// Cat implementation of the virtual method.
void Cat::makeSound() {

	std::cout << "Meow... meeeeeow..." << std::endl;
}