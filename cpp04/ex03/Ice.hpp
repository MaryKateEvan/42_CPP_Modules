/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 03:19:06 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria { // publicly inherits from AMateria.

	public:

		// Orthodox Canonical form elements:
		Ice();									// default constructor
		Ice(Ice const & to_copy);				// copy constructor
		~Ice();									// destructor
		Ice& operator=(Ice const & src);		// Assignment operator overload
		
		// The methods that the base class AMateria asks implementation for:
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif //ICE_HPP