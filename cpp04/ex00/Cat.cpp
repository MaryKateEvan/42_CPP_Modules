/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:17:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CAT_MSG(text) "🐈 \033[35m" << text << " for Cat called" << "\033[0m"

// Default constructor
Cat::Cat() : Animal() {
		
	std::cout << CAT_MSG("Default constructor") << std::endl;
	this->setType();
}

// Copy constructor
Cat::Cat(Cat const & to_copy) : Animal(to_copy) {

	std::cout << CAT_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Cat::~Cat () {

	std::cout << CAT_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
Cat& Cat::operator=(Cat const & src) {

	std::cout << CAT_MSG("Copy assignment operator") << std::endl;

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
void Cat::makeSound() const {

	std::cout << "🔊: 🐈 \033[35m" << BOLD("Meow... meeeeeow...") << "\033[0m 🔊" << std::endl;
}