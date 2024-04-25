/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 21:50:42 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {};

// Parameter constructor to assign the name taken as parameter:
ClapTrap::ClapTrap(std::string name) : _Name(name) {};

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

	if (this != &src)
		this->_fpnv = src.getRawBits();

	return *this;
}
