/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 03:10:18 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class ICharacter; //to inform the compiler that there is implementation for this class

class AMateria { // The parent class of Ice and Cure.

	protected:

		std::string _type;

	public:

		AMateria(std::string const & type); // custom string parameter constructor, required by the subject
		
		// Orthodox Canonical form elements:
		AMateria();									// default constructor
		AMateria(AMateria const & to_copy);			// copy constructor
		virtual ~AMateria();						// destructor
		AMateria& operator=(AMateria const & src);	// Assignment operator overload

		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0; // -> all the derived classes MUST provide implementation for this
		virtual void use(ICharacter& target); // -> if the derived class has implementation for this method, execute that implementation
};

#endif //AMATERIA_HPP