/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:54:53 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 00:03:16 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {

	// std::cout << "Default constructor for Point called" << std::endl;
}

// Copy constructor
Point::Point(Point const & to_copy) : _x(to_copy.getX()), _y(to_copy.getY()) {

	// std::cout << "Copy constructor for Point called" << std::endl;
}

// Required additional constructor:
Point::Point(const float x, const float y) : _x(x), _y(y) {

	// std::cout << "Float constructor for Point called" << std::endl;
}

// Destructor
Point::~Point () {

	// std::cout << "Destructor for Point called" << std::endl;
}

// Copy assignment Operator overload
Point & Point::operator=(Point const & src) {

	// std::cout << "Copy assignment operator for Point called" << std::endl;

	if (this != &src) {
		// I can not change the values, since x and y are const Fixed attributes.
	}
	return *this;
}

// Getter for the private attribute x:
const Fixed Point::getX() const {

	return this->_x;
}

// Getter for the private attribute y:
const Fixed Point::getY() const {

	return this->_y;
}