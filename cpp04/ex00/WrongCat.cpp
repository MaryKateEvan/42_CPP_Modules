/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:12:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define WrongCat_MSG(text) "🐈 \033[31m" << text << " for WrongCat called" << "\033[0m"

// Default constructor
WrongCat::WrongCat() : WrongAnimal() {
		
	std::cout << WrongCat_MSG("Default constructor") << std::endl;
	this->setType();
}

// Copy constructor
WrongCat::WrongCat(WrongCat const & to_copy) : WrongAnimal(to_copy) {

	std::cout << WrongCat_MSG("Copy constructor") << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
WrongCat::~WrongCat () {

	std::cout << WrongCat_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
WrongCat& WrongCat::operator=(WrongCat const & src) {

	std::cout << WrongCat_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		WrongAnimal::operator=(src);
	}
	return *this;
}

void WrongCat::setType() {

	this->type = "WrongCat";
}

// WrongCat's implementation of the method makeSound(), but not overriden since it's not virtual in the WrongAnimal class, so it will never be printed
void WrongCat::makeSound() const {

	std::cout << "🔊: 🐈 \033[31m" << BOLD("Meow... meeeeeow...") << "\033[0m 🔊" << std::endl;
}