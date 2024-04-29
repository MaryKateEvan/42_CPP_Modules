/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 04:46:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter { // publicly inherits from the Interface ICharacter

	private:

		std::string _Name;
		AMateria* _Inventory[4];
	
	public:

		Character(std::string const & name); //string parameter constructor
		
		// Orthodox Canonical form elements:
		Character();									// default constructor
		Character(Character const & to_copy);			// copy constructor
		~Character();									// destructor
		Character& operator=(Character const & src);	// Assignment operator overload
		
		// The methods that the base class ICharacter asks implementation for:
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif //CHARACTER_HPP