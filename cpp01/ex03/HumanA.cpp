/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:57:12 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 01:06:12 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// In HumanA, the constructor takes the Weapon:
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

//destructor
HumanA::~HumanA() {}

void HumanA::attack() const {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}