/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 06:43:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:

		std::string _Name;
	
	public:

		DiamondTrap(std::string name);
		DiamondTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage);
		
		// Orthodox Canonical form elements:
		DiamondTrap();									// default constructor
		DiamondTrap(DiamondTrap const & to_copy);			// copy constructor
		~DiamondTrap();								// destructor
		DiamondTrap& operator=(DiamondTrap const & src);	// Assignment operator overload

		// Inherited, overload member functions:
		void attack(const std::string& target);
		void printStatus() const;

		// Non-inherited, specific only to the DiamondTrap class:
		void guardGate();
};

#endif //DIAMONDTRAP_HPP