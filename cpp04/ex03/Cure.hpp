/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 03:14:41 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria { // publicly inherits from AMateria.

	public:

		// Orthodox Canonical form elements:
		Cure();									// default constructor
		Cure(Cure const & to_copy);				// copy constructor
		~Cure();								// destructor
		Cure& operator=(Cure const & src);		// Assignment operator overload
		
		// The methods that the base class AMateria asks implementation for:
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif //CURE_HPP