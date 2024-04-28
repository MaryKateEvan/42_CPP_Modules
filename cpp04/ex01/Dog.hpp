/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 15:39:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private:

		Brain* _dogBrain;
	
	public:

		// Orthodox Canonical form elements:
		Dog();								// default constructor
		Dog(Dog const & to_copy);			// copy constructor
		~Dog();								// destructor
		Dog& operator=(Dog const & src);	// Assignment operator overload

		void makeSound() const; //overrides the one from the base class Animal
};

#endif //DOG_HPP