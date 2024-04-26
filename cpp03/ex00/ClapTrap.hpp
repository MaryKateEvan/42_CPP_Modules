/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 03:15:31 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class ClapTrap {

	private:

		std::string _Name;
		unsigned int _HitPoints;
		unsigned int _EnergyPoints;
		unsigned int _AttackDamage; //the attack damage to create to the opponent
	
	public:

		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackdamage);
		
		// Orthodox Canonical form elements:
		ClapTrap();									// default constructor
		ClapTrap(ClapTrap const & to_copy);			// copy constructor
		~ClapTrap();								// destructor
		ClapTrap& operator=(ClapTrap const & src);	// Assignment operator overload

		//Getters for the private attributes:
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

		//Setters for the four private attributes:
		void setHitPoints(unsigned int hit_points);
		void setEnergyPoints(unsigned int energy_points);
		void setAttackDamage(unsigned int damage);

		// The required member functions:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void printStatus() const;
};

#endif //CLAPTRAP_HPP