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
DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), ScavTrap("unknown_clap_name"), FragTrap("unknown_clap_name") {

	this->_Name = "unknown";

	ScavTrap tmp;
	this->_EnergyPoints = tmp.getEnergyPoints();
	
	std::cout << "Constructor for DiamondTrap called" << std::endl;
}

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {

	this->_Name = name;

	ScavTrap tmp;
	this->_EnergyPoints = tmp.getEnergyPoints();

	std::cout << "Constructor for DiamondTrap called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(DiamondTrap const & to_copy) : ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy) {

	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
	this->_Name = to_copy.getName();
	// ClapTrap::_Name = to_copy._Name + "_clap_name"; -> I don't need this cause it has already been made in the Diamond object that's I'm copying from.
}

// Destructor
DiamondTrap::~DiamondTrap () {

	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

// Copy assignment Operator overload
DiamondTrap& DiamondTrap::operator=(DiamondTrap const & src) {

	std::cout << "Copy assignment operator for DiamondTrap called" << std::endl;

	if (this != &src) {
		// ClapTrap::operator=(src); //maybe I don't need this one, since it's called form the below two
		ScavTrap::operator=(src);
		FragTrap::operator=(src);
		this->_Name = src.getName();
	}
	return *this;
}

// Getter for the private attribute _Name
std::string DiamondTrap::getName() const {
	return this->_Name;
}

// Setter for the private attribute _Name
void DiamondTrap::setName(std::string name) {
	this->_Name = name;
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

