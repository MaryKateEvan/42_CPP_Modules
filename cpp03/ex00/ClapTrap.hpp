/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 21:52:22 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

	private:

		std::string _Name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;
	
	public:

		ClapTrap();									// default constructor
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & to_copy);			// copy constructor
		~ClapTrap();								// destructor

		ClapTrap& operator=(ClapTrap const & src);	// Assignment operator overload

		//Getters for the private attributes:

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif //CLAPTRAP_HPP