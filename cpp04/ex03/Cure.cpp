/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {} //-> calls the string constructor of AMateria

// Copy constructor
Cure::Cure(Cure const & to_copy) : AMateria(to_copy) {}

// Destructor
Cure::~Cure () {}

// Copy assignment Operator overload
Cure& Cure::operator=(Cure const & src) {

	if (this != &src) {
		this->_type = src._type; //? Is there a point doing that since it's alway gonna be Cure?
	}
	return *this;
}

// The pure virtual function for which Cure MUST provide implementation:
AMateria* Cure::clone() const {

	// Subject: "the member function clone() returns a new instance of the same type":
	return (new Cure(*this)); //call of the copy constructor
}

void Cure::use(ICharacter& target) {

	// Message expected: Cure: "* heals <name>’s wounds *"
	std::cout << "Cure: * heals " << "target_name's wounds *" << std::endl;
}