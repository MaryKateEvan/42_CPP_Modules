/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 02:06:27 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource { // publicly inherits from the interface IMateriaSource

	private:

		AMateria* memory[4]; // "The MateriaSource can know at most 4 Materias"
	
	public:

		// Orthodox Canonical form elements:
		MateriaSource();									// default constructor
		MateriaSource(MateriaSource const & to_copy);				// copy constructor
		~MateriaSource();								// destructor
		MateriaSource& operator=(MateriaSource const & src);		// Assignment operator overload
		
		// The pure virtual funtions from IMateriaSource that this class must provide implementation for
		void learnMateria(AMateria* new_mat);
		AMateria* createMateria(std::string const & type);
};

#endif //MATERIASOURCE_HPP