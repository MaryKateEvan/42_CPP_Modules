/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 21:16:30 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {

	this->_Name = "unknown ScavTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	
	std::cout << "Constructor for ScavTrap called" << std::endl;
}

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;

	std::cout << "Constructor for ScavTrap called" << std::endl;
}

// Additional Parameter Constructor, if the user wants to assign all attributes directly:
ScavTrap::ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage) 
	: ClapTrap(name, hitPoints, energyPoints, attackdamage) {
		
	std::cout << "Constructor for ScavTrap called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(ScavTrap const & to_copy) : ClapTrap(to_copy) {

	std::cout << "Copy constructor for ScavTrap called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap () {

	std::cout << "Destructor for ScavTrap called" << std::endl;
}

// Copy assignment Operator overload
ScavTrap& ScavTrap::operator=(ScavTrap const & src) {

	std::cout << "Copy assignment operator for ScavTrap called" << std::endl;

	if (this != &src) {
		ClapTrap::operator=(src);
	}
	return *this;
}

/*
*	Member function that performs an "attack" of _AttackDamage points to the opponent "target", and
*	costs 1 Energy Point to the attacker (current ScavTrap object). 
*	-	If hit points are 0 (which means no life remaining), the ScavTrap is dead and nothing can be done.
*	-	If ScavTrap has 0 Energy Points, no attack is performed.
*/
void ScavTrap::attack(const std::string& target) {

	if (this->_HitPoints == 0) {
		std::cout << "ScavTrap " << this->_Name << " has been defeated and powered-off. No attack can be made." << std::endl;
		return ;
	}
	if (this->_EnergyPoints >= 1) {
		(this->_EnergyPoints)--;
		std::cout << "ScavTrap " << this->_Name << BOLD(" attacks ") << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->_Name << " doesn't have enough energy points to attack " << target << std::endl;
	}
}

/*
*	Additional Member Function that prints the current state of Hit Points, Energy Points
*	and Attack Damage, of the the current ScavTrap object.
*/
void ScavTrap::printStatus() const {
	
	std::cout	<< "ScavTrap " << BOLD(this->_Name) << " currently has: "
				<< this->_HitPoints << " Hit Points, " 
				<< this->_EnergyPoints << " Energy Points, and "
				<< this->_AttackDamage << " Attack Damage." << std::endl;
}

/*
*	Non-inherited member function, specific only for the ScavTrap Class.
*/
void ScavTrap::guardGate() {

	if (this->_HitPoints != 0) {
		std::cout << "ScavTrap " << BOLD(this->_Name) << " is now in " << "\033[33m" << "Gate Keeper Mode." << "\033[0m" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << BOLD(this->_Name) << " is dead so can not be sent to Gate Keeping." << std::endl;
	}
}

