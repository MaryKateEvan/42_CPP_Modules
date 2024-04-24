/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:42:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 02:11:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fpnv(0) {

	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const & to_copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

// Destructor
Fixed::~Fixed () {

	std::cout << "Destructor called" << std::endl;
}

// Getter for the private attribute _fpnv:
int Fixed::getFpnv() const {

	return this->_fpnv;
}

// Copy assignment Operator overload:
Fixed & Fixed::operator=(Fixed const & src) {

	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &src)
		this->_fpnv = src.getFpnv();
	
	return *this;
}

int Fixed::getRawBits(void) const {

	
}

void Fixed::setRawBits(int const raw) {

	
}