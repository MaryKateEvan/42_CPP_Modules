/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:53:02 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 05:29:33 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	/* Combination 1*/
	ClapTrap A("Wall-e");
	ScavTrap B("Terminator");
	// /* Combination 2 */
	// ClapTrap A("Wall-e", 20, 10, 5);
	// ScavTrap B("Terminator", 15, 4, 3);
	
	// PART A: TESTING THE ATTACK
	
	unsigned int damageForAttack = 25;
	std::cout << "__________________________________________________________________________________________" << std::endl;
	std::cout << "\033[31m" << BOLD("\nTEST FOR THE ATTACK:") << "\033[0m" << std::endl;
	
	std::cout << UNDERLINE("\nState before the attack:") << std::endl;
	A.printStatus();
	B.printStatus();
	
	std::cout << "\033[31m" << UNDERLINE("\nThe attack:") << "\033[0m" << std::endl;
	A.setAttackDamage(damageForAttack);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());

	std::cout << UNDERLINE("\nState after the attack:") << std::endl;
	A.printStatus();
	B.printStatus();

	// PART B: TESTING THE REPAIR
	
	unsigned int amountToRepair = 3;
	std::cout << "__________________________________________________________________________________________" << std::endl;
	std::cout << "\033[36m" << BOLD("\nTEST FOR THE REPAIR:") << "\033[0m" << std::endl;

	std::cout << UNDERLINE("\nState before the repair:") << std::endl;
	B.printStatus();

	std::cout << "\033[36m" << UNDERLINE("\nThe repair:") << "\033[0m" << std::endl;
	B.beRepaired(amountToRepair);
	
	std::cout << UNDERLINE("\nState after the repair:") << std::endl;
	B.printStatus();

	// PART C: GATE KEEPER MODE
	std::cout << "__________________________________________________________________________________________" << std::endl;
	std::cout << "\033[33m" << BOLD("\nGATE KEEPER MODE:\n") << "\033[0m" << std::endl;
	B.guardGate();
	std::cout << "__________________________________________________________________________________________" << std::endl;
	std::cout << std::endl;

	return 0;
}
