/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:37:22 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define WrongAnimal_MSG(text) "\033[90m" << text << " for WrongAnimal called" << "\033[0m"

// Default constructor
WrongAnimal::WrongAnimal() {
		
	std::cout << WrongAnimal_MSG("Default constructor") << std::endl;
	this->type = "WrongAnimal";
}

// Copy constructor
WrongAnimal::WrongAnimal(WrongAnimal const & to_copy) {

	std::cout << WrongAnimal_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
WrongAnimal::~WrongAnimal () {

	std::cout << WrongAnimal_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
WrongAnimal& WrongAnimal::operator=(WrongAnimal const & src) {

	std::cout << WrongAnimal_MSG("Copy assignment operator") << std::endl;

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