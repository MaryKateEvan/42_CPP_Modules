/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 05:53:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() {
		
	std::cout << "Default constructor for Animal called" << std::endl;
	this->setType();
}

// Copy constructor
Animal::Animal(Animal const & to_copy) {

	std::cout << "Copy constructor for Animal called" << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Animal::~Animal () {

	std::cout << "Destructor for Animal called" << std::endl;
}

// Copy assignment Operator overload
Animal& Animal::operator=(Animal const & src) {

	std::cout << "Copy assignment operator for Animal called" << std::endl;

	if (this != &src) {
		this->type = src.type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

// Virtual function (method) so the implementation of the derived classes has priority in them.
void Animal::setType() {

	this->type = "Animal";
}

std::string Animal::getType() {

	return this->type;
}

// Virtual so that the implementation of the derived classes has priority.
void Animal::makeSound() {

	std::cout << "Animal here making random sound!!" << std::endl;
}