/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 06:23:02 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class Animal {

	protected:

		std::string type;

	public:

		// Orthodox Canonical form elements:
		Animal();								// default constructor
		Animal(Animal const & to_copy);			// copy constructor
		~Animal();								// destructor
		Animal& operator=(Animal const & src);	// Assignment operator overload

		virtual void setType();
		std::string getType() const;

		virtual void makeSound() const;
};

#endif //ANIMAL_HPP