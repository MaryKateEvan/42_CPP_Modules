/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 19:30:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class AAnimal {

	protected:

		std::string type;

	public:

		// Orthodox Canonical form elements:
		AAnimal();	//moved to the protected section so that AAnimal can not be instantiable
		AAnimal(AAnimal const & to_copy);			// copy constructor
		virtual ~AAnimal();						// destructor
		AAnimal& operator=(AAnimal const & src);	// Assignment operator overload

		std::string getType() const;

		virtual void makeSound() const = 0;//So now it is a pure virtual method! -> All the derived functions must provide implemetation for it, but this abstract class doesn't have to.
};

#endif //AAnimal_HPP