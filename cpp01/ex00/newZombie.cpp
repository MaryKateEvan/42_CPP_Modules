/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:07:27 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 11:07:50 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// function to dynamically allocate an object "Zombie"
Zombie* newZombie( std::string name ) {

	Zombie* new_zombie = new Zombie(name);
	return new_zombie;
	//I'm returning dynamically allocated memory, so it needs to be freed after.
}