/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:10:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		// Orthodox Canonical form elements:
		WrongCat();									// default constructor
		WrongCat(WrongCat const & to_copy);			// copy constructor
		~WrongCat();								// destructor
		WrongCat& operator=(WrongCat const & src);	// Assignment operator overload

		// Functions that override the ones from the base class Animal:
		void setType();
		void makeSound() const;
};

#endif //WRONGCAT_HPP