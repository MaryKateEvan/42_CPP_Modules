/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {} //-> calls the string constructor of AMateria

// Copy constructor
Ice::Ice(Ice const & to_copy) : AMateria(to_copy) {}

// Destructor
Ice::~Ice () {}

// Copy assignment Operator overload
Ice& Ice::operator=(Ice const & src) {

	if (this != &src) {
		this->_type = src._type; //? Is there a point doing that since it's alway gonna be ice?
	}
	return *this;
}

// The pure virtual function for which Ice MUST provide implementation:
AMateria* Ice::clone() const {

	// Subject: "the member function clone() returns a new instance of the same type":
	return (new Ice(*this)); //call of the copy constructor
}

void Ice::use(ICharacter& target) {

	// Message expected: Ice: "* shoots an ice bolt at <name> *"
	std::cout << "Ice: * shoots an ice bolt at " << "target_name?" << "*" << std::endl;
}