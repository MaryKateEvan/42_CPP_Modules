/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 21:01:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

		FragTrap(std::string name); //the constructor required from the subject
		FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage); //additional constructor for user needs
		
		// Orthodox Canonical form elements:
		FragTrap();									// default constructor
		FragTrap(FragTrap const & to_copy);			// copy constructor
		~FragTrap();								// destructor
		FragTrap& operator=(FragTrap const & src);	// Assignment operator overload

		void printStatus() const;

		// Non-inherited, specific only to the FragTrap class:
		void highFivesGuys(void);
};

#endif //FRAGTRAP_HPP