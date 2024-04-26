/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:42:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 00:49:01 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float power(float base, int exponent);

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {

	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const & to_copy) {

	// std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

// Int Parameter constructor, that converts the "num" to fixed-point value.
Fixed::Fixed(const int num) {

	// std::cout << "Int constructor called" << std::endl;
	
	this->_fixedPointValue = num << this->_fractBits;
	// Same as: num * (2 ^ _fractBits)
}

// Float Parameter constructor, that converts the "float_num" to fixed-point value.
Fixed::Fixed(const float float_num) {

	// std::cout << "Float constructor called" << std::endl;
	
	this->_fixedPointValue = static_cast<int> (roundf(float_num * power(2, _fractBits)));
}

// Destructor
Fixed::~Fixed () {

	// std::cout << "Destructor called" << std::endl;
}

// Copy assignment Operator overload
Fixed & Fixed::operator=(Fixed const & src) {

	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->_fixedPointValue = src.getRawBits();

	return *this;
}

// Getter for the private attribute _fixedPointValue
int Fixed::getRawBits() const {

	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// Setter for the private attribute _fixedPointValue
void Fixed::setRawBits(int const raw) {

	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

// Converts the fixed-point value to a floating-point value
float Fixed::toFloat() const {
	
	return this->_fixedPointValue / power(2, _fractBits);
}

// Converts the fixed-point value to an integer value
int Fixed::toInt() const {
	
	return this->_fixedPointValue >> this->_fractBits;
	// Same as: _fixedPointValue / (2 ^ _fractBits)
}

// Insertion Operator Overload, that inserts a floating-point respresentation of
// the fixed-point number into the output stream "out" passed as parameter
std::ostream & operator<<(std::ostream & out, Fixed const & i) {
	
	out << i.toFloat();
	return out;
}

float power(float base, int exponent) {
	
	float result = 1.0f;

	for (int i = 0; i < exponent; ++i) {
		result = result * base;
	}
	return result;
}

/*
*	1) COMPARISON OPERATORS OVERLOAD
*	Comparison of the passed by reference instance of Fixed class "b", with the
*	automatically passed instance "this" (c++ passes it as hidden first argument).
*	For all the comparisons, we compare the private attribute _fixedPointValue.
*	@param b: the instance that we wanna compare our current instance with.
*	@returns: the result of the comparison which can be true or false.
*/ 

bool Fixed::operator>(Fixed const & b) const {

	return (this->_fixedPointValue > b.getRawBits());
}

bool Fixed::operator<(Fixed const & b) const {

	return (this->_fixedPointValue < b.getRawBits());
}

bool Fixed::operator>=(Fixed const & b) const {

	return (this->_fixedPointValue >= b.getRawBits());
}

bool Fixed::operator<=(Fixed const & b) const {

	return (this->_fixedPointValue <= b.getRawBits());
}

bool Fixed::operator==(Fixed const & b) const {

	return (this->_fixedPointValue == b.getRawBits());
}

bool Fixed::operator!=(Fixed const & b) const {

	return (this->_fixedPointValue != b.getRawBits());
}

/*
*	2) ARITHMETIC OPERATORS OVERLOAD
*	Execution of the corresponding arithmetic operation (+, -, * or /) between
*	the float representations of the private attribute _fixedPointValue of i) the current 
*	instance "this" (passed automatically as first argument) and of ii) the passed 
*	by reference instance "b". And then the result is used by the corresponding 
*	parameter constructor, who creates a new object with the converted _fixedPointValue.
*	@param b: the instance whose the float representation of _fixedPointValue we want 
*			  to do the arithmetic operation with.
*	@returns: a new "Fixed" object, constructed with the above result, converted to fixedPointValue.
*/ 

Fixed Fixed::operator+(Fixed const & y) const {
	
	return (Fixed(this->toFloat() + y.toFloat()));
}

Fixed Fixed::operator-(Fixed const & y) const {
	
	return (Fixed(this->toFloat() - y.toFloat()));
}

Fixed Fixed::operator*(Fixed const & y) const {
	
	return (Fixed(this->toFloat() * y.toFloat()));
}

Fixed Fixed::operator/(Fixed const & y) const {
	
	return (Fixed(this->toFloat() / y.toFloat()));
}

/*
*	3) INCREMENT/DECREMENT OPERATORS OVERLOAD
*	  A. PRE-increment/decrement: these operators modify the object's state and return
*		 a reference (by convention) to the modified object, which allow to chain multiple
*		 pre-increment/decrement operations together.
*	  B. POST-increment/decrement: these operators also modify the object's state but return
*		 the object's original unmodified value before the operation. Their return type is
*		 not a reference because they return a copy of the original value.
*		 Note: the `(int)` is just a "dummy parameter" to distinguish the post- from the
*			   pre-in/decrement operators.
*/ 

// Pre-increment operator (++x)
Fixed & Fixed::operator++() {

	(this->_fixedPointValue)++;
	return (*this);
}

// Pre-decrement operator (--x)
Fixed & Fixed::operator--() {

	(this->_fixedPointValue)--;
	return (*this);
}

// Post-increment operator (x++)
Fixed Fixed::operator++(int) { //
	
	Fixed originalState = Fixed(*this);
	
	(this->_fixedPointValue)++;
	return originalState;
}

// Post decrement operator (x--)
Fixed Fixed::operator--(int) {

	Fixed originalState = Fixed(*this);
	
	(this->_fixedPointValue)--;
	return originalState;
}

/*
*	4) MIN AND MAX OVERLOADED MEMBER FUNCTIONS:
*	Static member functions of the class "Fixed", so they belong to the class itself and
*	not to individual objects. Thus, they can be used to compare different objects of the 
*	class and return the reference of the one with the maximum or minimum _fixedPointValue.
*/


Fixed & Fixed::min(Fixed & a, Fixed & b) {

	if (b < a)
		return b;
	else
		return a;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b) {
	
	if (b < a)
		return b;
	else
		return a;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {

	if (b > a)
		return b;
	else
		return a;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b) {

	if (b > a)
		return b;
	else
		return a;
}
