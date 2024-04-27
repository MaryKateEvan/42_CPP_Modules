/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 19:18:54 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
// Virtual inheritance so that no instance of ClapTrap subobject reaches the "grandchild" 
// class "DiamondTrap". Only one instance of ClapTrap passes to the derived ScavTrap only.

	public:

		ScavTrap(std::string name);
		ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage);
		
		// Orthodox Canonical form elements:
		ScavTrap();									// default constructor
		ScavTrap(ScavTrap const & to_copy);			// copy constructor
		~ScavTrap();								// destructor
		ScavTrap& operator=(ScavTrap const & src);	// Assignment operator overload

		// Inherited, overload member functions:
		void attack(const std::string& target);
		void printStatus() const;

		// Non-inherited, specific only to the ScavTrap class:
		void guardGate();
};

#endif //SCAVTRAP_HPP