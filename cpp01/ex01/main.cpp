/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:43:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 12:44:42 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	int N = 10;

	Zombie* ptr = zombieHorde(N, "Bob");
	if (!ptr)
		return (0);

	// In order to verify the allocation:
	std::cout << std::endl;
	std::cout << "The Horde announces itself, one zombie at a time:" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "Zombie no." << i + 1 << ":  ";
		ptr[i].announce();
	}
	std::cout << std::endl;
	
	// and then we free all the zombie objects of the array:
	delete [] ptr;
	std::cout << std::endl;
	
	return (0);
}