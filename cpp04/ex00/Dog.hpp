/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 06:27:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Dog : public Animal {

	public:

		// Orthodox Canonical form elements:
		Dog();								// default constructor
		Dog(Dog const & to_copy);			// copy constructor
		~Dog();								// destructor
		Dog& operator=(Dog const & src);	// Assignment operator overload

		// Functions that override the ones from the base class Animal:
		void setType();
		void makeSound() const;
};

#endif //DOG_HPP