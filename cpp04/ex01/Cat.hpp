/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 15:40:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	private:

		Brain* _catBrain;
	
	public:

		// Orthodox Canonical form elements:
		Cat();								// default constructor
		Cat(Cat const & to_copy);			// copy constructor
		~Cat();								// destructor
		Cat& operator=(Cat const & src);	// Assignment operator overload

		void makeSound() const; //overrides the one from the base class Animal
};

#endif //CAT_HPP