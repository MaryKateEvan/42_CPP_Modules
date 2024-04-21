/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:03:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 01:07:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// In Human B, the constructor doesn't take the Weapon:
HumanB::HumanB(std::string name) : _name(name) {

	_weapon = NULL;
}

// Destructor
HumanB::~HumanB() {}

void HumanB::attack() const {

	if (_weapon)
		std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon to attack" << std::endl;
}

void HumanB::setWeapon(Weapon& to_set) {
	
	_weapon = &to_set;
}
