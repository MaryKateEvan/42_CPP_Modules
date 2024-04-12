/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:09:51 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 12:41:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//setter for the private attribute _name:
void Zombie::setName( std::string name) {
	this->_name = name;
}

//destructor:
Zombie::~Zombie(void) {
	
	std::cout << this->_name << " is destroyed." << std::endl;
}

//the method "announce":
void Zombie::announce( void ) const {
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


