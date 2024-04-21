/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:11:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 01:02:48 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string new_type) : _type(new_type) {}

// Destructor
Weapon::~Weapon() {}

// Member function that returns a const reference to the type string
std::string const & Weapon::getType() const {
	
	return this->_type;
}

// Sets the type of the Weapon object, as the one passed as parameter
void Weapon::setType(std::string new_one) {
	
	_type = new_one;
}
