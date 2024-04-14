/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:57:12 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 10:07:42 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack() const {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

// The constructor takes the Weapon in HumanA:
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

//destructor
HumanA::~HumanA() {}