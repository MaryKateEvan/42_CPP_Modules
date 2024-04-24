/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:42:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 21:08:22 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float power(float base, int exponent);

// Default constructor
Fixed::Fixed() : _fpnv(0) {

	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const & to_copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

// Int Parameter constructor, that converts the num passed as parameter 
// to the corresponding fixed-point value.
Fixed::Fixed(const int num) {

	std::cout << "Int constructor called" << std::endl;
	
	this->_fpnv = num << this->_fractBits; //so that we move the bits of our int num 8 places to the left, in order to have 8 fractional bits.
	// Same as: num * (2 ^ _fractBits)
}

// Float Parameter constructor, that converts the float_num passed as
// parameter to the corresponding fixed-point value.
Fixed::Fixed(const float float_num) {

	std::cout << "Float constructor called" << std::endl;
	
	this->_fpnv = static_cast<int> (roundf(float_num * power(2, _fractBits)));
	// roundf rounds to the closest integer. 
	// So 42.42 * 256 = 10859.52 -> the roundf will make it 10860
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

	// std::cout << "getRawBits member function called" << std::endl;

	return this->_fpnv;
}

// Setter for the private attribute _fpnv
void Fixed::setRawBits(int const raw) {

	// std::cout << "setRawBits member function called" << std::endl;

	this->_fpnv = raw;
}

// Converts the fixed-point value to a floating-point value
float Fixed::toFloat( void ) const {
	
	return this->_fpnv / power(2, _fractBits);
}

// Converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
	
	return this->_fpnv >> this->_fractBits; // 8 to the right, since we want integer so we can ignore the 8 fractional bits.
	// Same as: _fpnv / (2 ^ _fractBits)
}


// Insertion Operator Overload, that inserts a floating-point respresentation of
// the fixed-point number into the output stream object passed as parameter
std::ostream & operator<<(std::ostream & out, Fixed const & i) {
	
	out << i.toFloat();
	return out;
}


float power(float base, int exponent) {
	
	float result = 1.0F;

	for (int i = 0; i < exponent; ++i) {
		result = result * base;
	}
	return result;
}
