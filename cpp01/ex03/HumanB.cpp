/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:03:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 09:09:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack() const {

	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

HumanB::HumanB(std::string name) : _name(name) {
	
}

HumanB::~HumanB() {}
