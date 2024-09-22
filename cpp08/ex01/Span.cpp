/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:54 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 01:58:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _maxStorage(0) {}

// Parameter constructor
Span::Span(unsigned int N) : _maxStorage(N) {
	this->_vec.reserve(_maxStorage);
}

// Copy constructor
Span::Span(Span const & to_copy) : _maxStorage(to_copy._maxStorage), _vec(to_copy._vec) {}

// Copy assignment Operator overload
Span& Span::operator=(Span const & src) {

	if (this != &src) {
		this->_maxStorage = src._maxStorage;
		this->_vec = src._vec;
	}
	return *this;
}

// Destructor
Span::~Span () {}


void Span::addNumber(int& num) {
	
	if (_vec.size() < _maxStorage)
		_vec.push_back(num);
	else
		throw SpanOutOfSpaceException();
}


// // Override of the what method in the two custom exceptions:
const char* Span::SpanOutOfSpaceException::what() const throw() {
	return "span out of space!";
}
// const char* Span::GradeTooLowException::what() const throw() {
// 	return "grade is too low!";
// }
// const char* Span::AlreadySignedException::what() const throw() {
// 	return "Span is already signed!";
// }