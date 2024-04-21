/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:43:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/21 23:26:50 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	std::cout << std::endl;
	std::cout << "1) Zombie object on stack:" << std::endl;
	randomChump("Zed the Undying");

	std::cout << std::endl;
	std::cout << "2) Zombie object on heap:" << std::endl;
	Zombie*	z_ptr = newZombie("Ghastly Grim");
	z_ptr->announce();
	delete z_ptr;
	std::cout << std::endl;

	return 0;
}
