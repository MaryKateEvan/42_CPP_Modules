/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:00:51 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/21 23:31:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
*	Creates a "Zombie" object on the Stack, calls its member function "announce"
*	and the object is destroyed with the end of this function by the class' destructor.
*	@param name: the name to assign to the private attribute "_name" of the Zombie object.
*/
void randomChump(std::string name) {

	Zombie random_chump = Zombie(name);
	random_chump.announce();
}