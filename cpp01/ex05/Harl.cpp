/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:21:18 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 15:35:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	
	std::cout << "I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	
	// Array of the level strings:
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	// Array of pointers to the 4 member functions of Harl class:
	void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	for (int j = 0; level[j]; j++) {
		level[j] = std::toupper(level[j]);
	}
	
	for (int i = 0; i < 4; i++) {

		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << level << ": not a valid level of complain." << std::endl;
}