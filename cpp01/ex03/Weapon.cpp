/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:11:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/13 12:55:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const & Weapon::getType() const {
	
	return this->_type;
}

void Weapon::setType(std::string new_one) {
	
	_type = new_one;
}

Weapon::Weapon(std::string new_type) {
	
	this->setType(new_type);
}

Weapon::~Weapon() {
}

