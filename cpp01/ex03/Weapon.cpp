/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:11:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 10:14:24 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// "a getType() member function that returns a const reference to type"
std::string const & Weapon::getType() const {
	
	return this->_type;
}

void Weapon::setType(std::string new_one) {
	
	_type = new_one;
}

// Constructor:
Weapon::Weapon(std::string new_type) : _type(new_type) {}

// Destructor:
Weapon::~Weapon() {}
