/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:20:57 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 10:08:12 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {

	// Test for HumanA:
	std::cout << UNDERLINE("1) Test for HumanA class:") << std::endl;
	Weapon clubA = Weapon("crude spiked club");
	HumanA bob("Bob", clubA);
	bob.attack();
	clubA.setType("some other type of club");
	bob.attack();

	// Test for HumanB:
	std::cout << UNDERLINE("2) Test for HumanB class:") << std::endl;
	Weapon clubB = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(clubB);
	jim.attack();
	clubB.setType("some other type of club");
	jim.attack();
	
	return 0;
}