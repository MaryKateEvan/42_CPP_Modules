/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#define AMATERIA_MSG(text) "\033[90m" << text << " for AMateria called" << "\033[0m"

// Default constructor
AMateria::AMateria() : _type("") {
		
	std::cout << AMATERIA_MSG("Default constructor") << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {

	std::cout << AMATERIA_MSG("String Parameter constructor") << std::endl;
}

// Copy constructor
AMateria::AMateria(AMateria const & to_copy) {

	std::cout << AMATERIA_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
AMateria::~AMateria () {

	std::cout << AMATERIA_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
AMateria& AMateria::operator=(AMateria const & src) {

	std::cout << AMATERIA_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		this->_type = src._type; //it's protected so i can take it directly. I don't need a getter
	}
	return *this;
}

