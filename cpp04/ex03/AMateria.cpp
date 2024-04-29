/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("undefined") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

// Copy constructor
AMateria::AMateria(AMateria const & to_copy) {

	*this = to_copy;
}

// Destructor
AMateria::~AMateria () {}

// Copy assignment Operator overload
AMateria& AMateria::operator=(AMateria const & src) {

	if (this != &src) {
		this->_type = src._type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

std::string const & AMateria::getType() const {

	return this->_type;
}

void AMateria::use(ICharacter& target) {

	(void)target;
	// not reached because the derived classes provide implementation for this
	// so they will have priority since it's a virtual function in out abstract class AMateria
}