/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:23:27 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 00:05:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
*	Function that allocates N Zombie objects in a single allocation, and initializes
*	each one of them with the "name" passed as parameter.
*	@param N: the number of Zombie objects to allocate. If negative or zero, the functions returns.
*	@param name: the name to assign to all the zombie objects of the horde.
*	@returns a pointer to the first Zombie object of the dynamically allocated array of N Zombie objects.
*/
Zombie*	zombieHorde(int N, std::string name) {

	if (N <= 0) {
		std::cout << "N must be a positive number." << std::endl;
		return (NULL);
	}

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
