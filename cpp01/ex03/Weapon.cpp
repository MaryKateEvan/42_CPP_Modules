/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:11:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 08:56:06 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// "a getType() member fubnctions that returns a const reference to type"
std::string const & Weapon::getType() const {
	
	return this->_type;
}


void Weapon::setType(std::string new_one) {
	
	_type = new_one;
}

//? For constructor what is better: 
//this?
Weapon::Weapon(std::string new_type) {
	
	this->setType(new_type);
}
//or this:
// Weapon::Weapon(std::string new_type) : _type(new_type) {}

Weapon::~Weapon() {}

