/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 02:53:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
	: _Name("unknown"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
		
	std::cout << "Constructor called" << std::endl;
};

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
ClapTrap::ClapTrap(std::string name)
	: _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
		
	std::cout << "Constructor called" << std::endl;
};

// Additional Parameter Constructor, if the user wants to assign all attributes directly:
ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage) 
	: _Name(name), _HitPoints(hitPoints), _EnergyPoints(energyPoints), _AttackDamage(attackdamage) {
		
	std::cout << "Constructor called" << std::endl;
};

// Copy constructor
ClapTrap::ClapTrap(ClapTrap const & to_copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
ClapTrap::~ClapTrap () {

	std::cout << "Destructor called" << std::endl;
}

// Copy assignment Operator overload
ClapTrap& ClapTrap::operator=(ClapTrap const & src) {

	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src) {
		this->_Name = src.getName();
		this->_HitPoints = src.getHitPoints();
		this->_EnergyPoints = src.getEnergyPoints();
		this->_AttackDamage = src.getAttackDamage();
	}
	return *this;
}

// GETTERS for the private attributes:
std::string ClapTrap::getName() const {
	return this->_Name;
}
unsigned int ClapTrap::getHitPoints() const {
	return this->_HitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const {
	return this->_EnergyPoints;
}
unsigned int ClapTrap::getAttackDamage() const {
	return this->_AttackDamage;
}

// SETTERS for the three private, moddifiable attributes:
void ClapTrap::setHitPoints(unsigned int hit_points) {
	this->_HitPoints = hit_points;
}
void ClapTrap::setEnergyPoints(unsigned int energy_points) {
	this->_EnergyPoints = energy_points;
}
void ClapTrap::setAttackDamage(unsigned int damage) {
	this->_AttackDamage = damage;
}

// THE THREE REQUIRED MEMBER FUNCTIONS:
/*
*	1) Member function that performs an "attack" of _AttackDamage points to the opponent "target", and
*	costs 1 Energy Point to the attacker (current ClapTrap object). If 0 Energy Points, no attack performed.
*/
void ClapTrap::attack(const std::string& target) {

	if (this->_EnergyPoints >= 1) {
		(this->_EnergyPoints)--;
		std::cout << "ClapTrap " << this->_Name << BOLD(" attacks ") << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_Name << " doesn't have enough energy points to attack " << target << std::endl;
	}
}

/*
*	2) Member function that reduces the current object's Hit Points according to the attack that is receiving. 
*	If the attack leads to 0 Hit Point, the current "ClapTrap" has been defeated.
*/
void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_HitPoints >= amount) {
		this->_HitPoints -= amount;
		std::cout << "ClapTrap " << this->_Name << BOLD(" takes damage ") << "of " << amount << " hit points." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_Name << BOLD(" takes damage ") << "of " << this->_HitPoints << " hit points and has been defeated!" << std::endl;
		this->_HitPoints = 0;
	}
}

/*
*	3) Member function that recovers "amount" Hit Points to the current ClapTrap; an action that costs 1 Energy Point 
*	to the ClapTrap ans so is performed only if the ClapTrap has at least 1 Energy Point.
*/
void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_EnergyPoints >= 1) {
		(this->_EnergyPoints)--;
		this->_HitPoints += amount;
		std::cout << "ClapTrap " << this->_Name << BOLD(" receives repair ") << "of " << amount << " hit points" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_Name << " doesn't have enough energy points to repair itself." << std::endl;
	}
}

/*
*	Additional Member Function that prints the current state of Hit Points, Energy Points
*	and Attack Damage, of the the currentClapTrap object.
*/
void ClapTrap::printStatus() const {
	
	std::cout	<< "ClapTrap " << BOLD(this->_Name) << " currently has: "
				<< this->_HitPoints << " Hit Points, " 
				<< this->_EnergyPoints << " Energy Points, and "
				<< this->_AttackDamage << " Attack Damage." << std::endl;
}

