/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:53:02 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 01:50:50 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	ClapTrap A("Wall-e");
	ClapTrap B("Siri");
	
	// PART A: TESTING THE ATTACK
	
	unsigned int damageForAttack = 1;
	std::cout << "\033[31m" << BOLD_UNDERLINE("\nTEST FOR THE ATTACK:") << "\033[0m" << std::endl;
	
	std::cout << UNDERLINE("\nState before the attack:") << std::endl;
	A.printStatus();
	B.printStatus();
	
	std::cout << UNDERLINE("\nThe attack:") << std::endl;
	A.setAttackDamage(damageForAttack);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());

	std::cout << UNDERLINE("\nState after the attack:") << std::endl;
	A.printStatus();
	B.printStatus();

	// PART B: TESTING THE REPAIR
	
	unsigned int amountToRepair = 3;
	std::cout << "\033[36m" << BOLD_UNDERLINE("\nTEST FOR THE REPAIR:") << "\033[0m" << std::endl;

	std::cout << UNDERLINE("\nState before the repair:") << std::endl;
	B.printStatus();

	std::cout << UNDERLINE("\nThe repair:") << std::endl;
	B.beRepaired(amountToRepair);
	
	std::cout << UNDERLINE("\nState after the repair:") << std::endl;
	B.printStatus();
	std::cout << std::endl;

	return 0;
}
