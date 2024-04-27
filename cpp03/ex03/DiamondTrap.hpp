/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 19:02:31 by mevangel         ###   ########.fr       */
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
		
		// Orthodox Canonical form elements:
		DiamondTrap();									// default constructor
		DiamondTrap(DiamondTrap const & to_copy);			// copy constructor
		~DiamondTrap();								// destructor
		DiamondTrap& operator=(DiamondTrap const & src);	// Assignment operator overload

		// Getter and Setter for the private attribute _Name:
		std::string getName() const;
		void setName(std::string name);

		// Inherited, overload member functions:
		void attack(const std::string& target);
		void printStatus() const;

		// Non-inherited, specific only to the DiamondTrap class:
		void whoAmI();

		// void setCorrectValues();
};

#endif //DIAMONDTRAP_HPP