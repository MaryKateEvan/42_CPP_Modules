/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:43:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 00:12:16 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	int N = 5;

	Zombie* ptr = zombieHorde(N, "Bob");
	if (!ptr)
		return (0);

	std::cout << std::endl;
	std::cout << "The Horde announces itself, one zombie at a time:" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "\033[4m" << "Announce from Zombie no." << i + 1 << "\033[0m" << ": ";
		ptr[i].announce();
	}
	std::cout << std::endl;

	delete [] ptr;
	std::cout << std::endl;
	
	return (0);
}
