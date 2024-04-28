/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#define AANIMAL_MSG(text) "\033[90m" << text << " for AAnimal called" << "\033[0m"

// Default constructor
AAnimal::AAnimal() {
		
	std::cout << AANIMAL_MSG("Default constructor") << std::endl;
	this->type = "Animal";
}

// Copy constructor
AAnimal::AAnimal(AAnimal const & to_copy) {

	std::cout << AANIMAL_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
AAnimal::~AAnimal () {

	std::cout << AANIMAL_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
AAnimal& AAnimal::operator=(AAnimal const & src) {

	std::cout << AANIMAL_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		this->type = src.type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

std::string AAnimal::getType() const {

	return this->type;
}

