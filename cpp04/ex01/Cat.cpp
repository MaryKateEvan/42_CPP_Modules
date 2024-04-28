/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 16:04:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CAT_MSG(text) "🐈 \033[35m" << text << " for Cat called" << "\033[0m"

// Default constructor
Cat::Cat() : Animal() {
		
	std::cout << CAT_MSG("Default constructor") << std::endl;
	this->type = "Cat";
	this->_catBrain = new Brain();
}

// Copy constructor
Cat::Cat(Cat const & to_copy) : Animal(to_copy) {

	std::cout << CAT_MSG("Copy constructor") << std::endl;
	this->_catBrain = new Brain(*(to_copy._catBrain)); //the copy constructor takes a reference, so i need to dereference my brain pointer
}

// Destructor
Cat::~Cat () {

	delete _catBrain; // calls the destructor of brain
	std::cout << CAT_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
Cat& Cat::operator=(Cat const & src) {

	std::cout << CAT_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		Animal::operator=(src); //? does this change the type though?
		_catBrain = src._catBrain; //? the pointers, ?
		// *_catBrain = *src._catBrain; //? or the values?
	}
	return *this;
}

// Cat implementation of the virtual method.
void Cat::makeSound() const {

	std::cout << "🔊: 🐈 \033[35m" << BOLD("Meow... meeeeeow...") << "\033[0m 🔊" << std::endl;
}