/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 16:04:58 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define DOG_MSG(text) "🐶 \033[36m" << text << " for Dog called" << "\033[0m"

// Default constructor
Dog::Dog() : Animal() {
		
	std::cout << DOG_MSG("Default constructor") << std::endl;
	this->type = "Dog";
	this->_dogBrain = new Brain();
}

// Copy constructor
Dog::Dog(Dog const & to_copy) : Animal(to_copy) {

	std::cout << DOG_MSG("Copy constructor") << std::endl;
	this->_dogBrain = new Brain(*(to_copy._dogBrain)); //the copy constructor takes a reference, so i need to dereference my brain pointer
}

// Destructor
Dog::~Dog () {

	delete _dogBrain; // calls teh destructor of Brain
	std::cout << DOG_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
Dog& Dog::operator=(Dog const & src) {

	std::cout << DOG_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		Animal::operator=(src);
	}
	return *this;
}

// Dog implementation of the virtual method.
void Dog::makeSound() const {

	std::cout << "🔊: 🐶 \033[36m" << BOLD("Woof! Woof!!! Baaaark") << "\033[0m 🔊" << std::endl;
}
