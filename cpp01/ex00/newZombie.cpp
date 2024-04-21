/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:07:27 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/21 23:21:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
*	Dynamically allocates an object of the class "Zombie", names it with the given
*	argument and returns the pointer to the dynamically allocated object.
*	@param name: the name to assign to the private attribute "_name" of the object.
*/
Zombie* newZombie(std::string name) {

	Zombie* new_zombie = new Zombie(name);
	return new_zombie;
}