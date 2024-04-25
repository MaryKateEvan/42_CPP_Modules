/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 22:09:16 by mevangel         ###   ########.fr       */
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
	*this = to_copy;
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
int ClapTrap::getHitPoints() const {
	return this->_HitPoints;
}
int ClapTrap::getEnergyPoints() const {
	return this->_EnergyPoints;
}
int ClapTrap::getAttackDamage() const {
	return this->_AttackDamage;
}

