/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:57:12 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/13 13:09:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack() const {

	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(Weapon& weapon) {

	_Weapon = weapon;
}