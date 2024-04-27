/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 21:16:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {

	this->_Name = "unknown FragTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	
	std::cout << "Constructor for FragTrap called" << std::endl;
}

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;

	std::cout << "Constructor for FragTrap called" << std::endl;
}

// Additional Parameter Constructor, if the user wants to assign all attributes directly:
FragTrap::FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage) 
	: ClapTrap(name, hitPoints, energyPoints, attackdamage) {
		
	std::cout << "Constructor for FragTrap called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(FragTrap const & to_copy) : ClapTrap(to_copy) {

	std::cout << "Copy constructor for FragTrap called" << std::endl;
}

// Destructor
FragTrap::~FragTrap () {

	std::cout << "Destructor for FragTrap called" << std::endl;
}

// Copy assignment Operator overload
FragTrap& FragTrap::operator=(FragTrap const & src) {

	std::cout << "Copy assignment operator for FragTrap called" << std::endl;

	if (this != &src) {
		ClapTrap::operator=(src);
	}
	return *this;
}

/*
*	Additional Member Function that prints the current state of Hit Points, Energy Points
*	and Attack Damage, of the the current FragTrap object.
*/
void FragTrap::printStatus() const {
	
	std::cout	<< "FragTrap " << BOLD(this->_Name) << " currently has: "
				<< this->_HitPoints << " Hit Points, " 
				<< this->_EnergyPoints << " Energy Points, and "
				<< this->_AttackDamage << " Attack Damage." << std::endl;
}

/*
*	Non-inherited member function, specific only for the FragTrap Class, that
*	prints a message of requesting a high five: ✋
*/
void FragTrap::highFivesGuys(void) {

	if (this->_HitPoints != 0) {
		std::cout << "FragTrap " << BOLD(this->_Name) << " is in a good mood today and requests a high five!! ✋" << std::endl;
	}
	else {
		std::cout << " If FragTrap " << BOLD(this->_Name) << " was still alive would ask for a high five ✋ now!" << std::endl;
	}
}

