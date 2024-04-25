/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:53:02 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 00:20:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	ClapTrap A("Wall-e");
	ClapTrap B("lorenzo");

	
	A.setAttackDamage(5);
	A.attack(B.getName());
	// A loses 1 energy point. So if A had 0 energy points, he can not attack.

	
	B.takeDamage(A.getAttackDamage());
	//If B has 5 or more hit points -> B loses 5 hit points.
	B.beRepaired(3); //from 5 hit points, now he has 8
	// AND loses 1 energy point for the repair.
	
	return 0;
}
