/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 07:20:33 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define ANIMAL_MSG(text) "\033[90m" << text << " for Animal called" << "\033[0m"

// Default constructor
Animal::Animal() {
		
	std::cout << ANIMAL_MSG("Default constructor") << std::endl;
	this->setType();
}

// Copy constructor
Animal::Animal(Animal const & to_copy) {

	std::cout << ANIMAL_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Animal::~Animal () {

	std::cout << ANIMAL_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
Animal& Animal::operator=(Animal const & src) {

	std::cout << ANIMAL_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		this->type = src.type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

// Virtual function (method) so the implementation of the derived classes has priority in them.
void Animal::setType() {

	this->type = "Animal";
}

std::string Animal::getType() const {

	return this->type;
}

// Virtual so that the implementation of the derived classes has priority.
void Animal::makeSound() const {

	std::cout << "🔊: \033[90m" << BOLD("Animal here making random sound!!") << "\033[0m 🔊 " << std::endl;
}