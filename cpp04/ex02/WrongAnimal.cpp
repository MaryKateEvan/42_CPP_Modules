/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 21:10:12 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define WRONG_ANIMAL(text) "\033[90m" << text << " for WrongAnimal called" << "\033[0m"

// Default constructor
WrongAnimal::WrongAnimal() {
		
	std::cout << WRONG_ANIMAL("Default constructor") << std::endl;
	this->type = "WrongAnimal";
}

// Copy constructor
WrongAnimal::WrongAnimal(WrongAnimal const & to_copy) {

	std::cout << WRONG_ANIMAL("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
WrongAnimal::~WrongAnimal () {

	std::cout << WRONG_ANIMAL("destructor") << std::endl;
}

// Copy assignment Operator overload
WrongAnimal& WrongAnimal::operator=(WrongAnimal const & src) {

	std::cout << WRONG_ANIMAL("Copy assignment operator") << std::endl;

	if (this != &src) {
		this->type = src.type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

std::string WrongAnimal::getType() const {

	return this->type;
}

// Virtual so that the implementation of the derived classes has priority.
void WrongAnimal::makeSound() const {

	std::cout << "🔊: \033[90m" << BOLD("WrongAnimal here making weird sound!! ❌") << "\033[0m 🔊 " << std::endl;
}