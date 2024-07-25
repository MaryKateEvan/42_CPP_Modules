/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/25 05:44:25 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _Name("unknown") {
		
	std::cout << "Constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const & to_copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy; //assignment operator overload called
}

// Destructor
Bureaucrat::~Bureaucrat () {

	std::cout << "Destructor called" << std::endl;
}

// Copy assignment Operator overload
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src) {
		this->_Name = src.getName();
	}
	return *this;
}

// GETTERS for the private attributes:
std::string Bureaucrat::getName() const {
	return this->_Name;
}

short Bureaucrat::getGrade() const {
	return this->_Grade;
}

