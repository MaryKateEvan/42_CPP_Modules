/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:37:48 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 15:36:23 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {

	private:

		std::string ideas[100];

	public:

		// Orthodox Canonical form elements:
		Brain();								// default constructor
		Brain(Brain const & to_copy);			// copy constructor
		~Brain();								// destructor
		Brain& operator=(Brain const & src);	// Assignment operator overload

		void setIdea();
		std::string getIdea() const;
};

#endif //BRAIN_HPP