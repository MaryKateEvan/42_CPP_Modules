/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:09:51 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 00:15:01 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie() {}

// destructor:
Zombie::~Zombie() {

	std::cout << this->_name << " is destroyed." << std::endl;
}

//setter for the private attribute "_name":
void Zombie::setName(std::string name) {

	this->_name = name;
}

//the method "announce":
void Zombie::announce(void) const {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
