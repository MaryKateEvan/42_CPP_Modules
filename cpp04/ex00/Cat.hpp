/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 06:04:34 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Cat : public Animal {

	public:

		// Orthodox Canonical form elements:
		Cat();								// default constructor
		Cat(Cat const & to_copy);			// copy constructor
		~Cat();								// destructor
		Cat& operator=(Cat const & src);	// Assignment operator overload

		// Functions that override the ones from the base class Animal:
		void setType();
		void makeSound();
};

#endif //CAT_HPP