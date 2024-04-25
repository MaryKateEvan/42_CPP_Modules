/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 00:13:51 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() {};

// Parameter constructor to assign the name taken as parameter, and initialize the other three attributes.
ClapTrap::ClapTrap(std::string name)
	: _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {};

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

	std::cout << "Copy assignment operator called" << std::endl;

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

// SETTERS for the three private attributes:
void ClapTrap::setHitPoints(unsigned int hit_points) {
	this->_HitPoints = hit_points;
}
void ClapTrap::setEnergyPoints(unsigned int energy_points) {
	this->_EnergyPoints = energy_points;
}
void ClapTrap::setAttackDamage(unsigned int damage) {
	this->_AttackDamage = damage;
}

// The FOUR required member functions:

void ClapTrap::attack(const std::string& target) {

	if (this->_EnergyPoints >= 1) {
		(this->_EnergyPoints)--;
		std::cout << "ClapTrap " << this->_Name << BOLD(" attacks ") << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_Name << " doesn't have enough energy points to attack " << target << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_HitPoints >= amount) {
		this->_HitPoints -= amount;
		std::cout << "ClapTrap " << this->_Name << BOLD(" takes damage ") << "of " << amount << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_Name << BOLD(" takes damage ") << "of " << this->_HitPoints << std::endl;
		this->_HitPoints = 0;
	}
}

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


