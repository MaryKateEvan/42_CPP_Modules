/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:42:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 02:40:29 by mevangel         ###   ########.fr       */
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

// Copy assignment Operator overload
Fixed & Fixed::operator=(Fixed const & src) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->_fpnv = src.getRawBits();

	return *this;
}

// Getter for the private attribute _fpnv
int Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;

	return this->_fpnv;
}

// Setter for the private attribute _fpnv
void Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;

	this->_fpnv = raw;
}