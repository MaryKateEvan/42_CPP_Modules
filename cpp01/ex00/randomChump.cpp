/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:00:51 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 11:08:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// function to create an object "Zombie" on the Stack.
void randomChump( std::string name ) {

	Zombie random_chump = Zombie(name);
	random_chump.announce();
	// random_chump exists only in the scope of this function!
	// destructor is called here, with this function being terminated
}