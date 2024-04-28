/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 21:14:08 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class WrongAnimal {

	protected:

		std::string type;

	public:

		// Orthodox Canonical form elements:
		WrongAnimal();										// default constructor
		WrongAnimal(WrongAnimal const & to_copy);			// copy constructor
		virtual ~WrongAnimal();								// destructor
		WrongAnimal& operator=(WrongAnimal const & src);	// Assignment operator overload

		std::string getType() const;

		void makeSound() const;
};

#endif //WRONGANIMAL_HPP