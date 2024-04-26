/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 05:28:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap() {

	this->_Name = "unknown DiamondTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	
	std::cout << "Constructor for DiamondTrap called" << std::endl;
};

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {

	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;

	std::cout << "Constructor for DiamondTrap called" << std::endl;
};

// Additional Parameter Constructor, if the user wants to assign all attributes directly:
DiamondTrap::DiamondTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage) 
	: ClapTrap(name, hitPoints, energyPoints, attackdamage) {
		
	std::cout << "Constructor for DiamondTrap called" << std::endl;
};

// Copy constructor
DiamondTrap::DiamondTrap(DiamondTrap const & to_copy) : ClapTrap(to_copy) {

	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap () {

	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

// Copy assignment Operator overload
DiamondTrap& DiamondTrap::operator=(DiamondTrap const & src) {

	std::cout << "Copy assignment operator for DiamondTrap called" << std::endl;

	if (this != &src) {
		ClapTrap::operator=(src);
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target) {

	ScavTrap::attack(target);
}

/*
*	Additional Member Function that prints the current state of Hit Points, Energy Points
*	and Attack Damage, of the the current DiamondTrap object.
*/
void DiamondTrap::printStatus() const {
	
	std::cout	<< "DiamondTrap " << BOLD(this->_Name) << " currently has: "
				<< this->_HitPoints << " Hit Points, " 
				<< this->_EnergyPoints << " Energy Points, and "
				<< this->_AttackDamage << " Attack Damage." << std::endl;
}

/*
*	Non-inherited member function, specific only for the DiamondTrap Class.
*/
void DiamondTrap::whoAmI() {

	std::cout << "DiamondTrap name: " << this->_Name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}

