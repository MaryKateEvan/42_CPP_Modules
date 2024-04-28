/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 22:16:27 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class AMateria {

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