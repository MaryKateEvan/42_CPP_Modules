/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/25 23:22:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _Name("unknown"), _Grade(150) {

	std::cout << "Constructor called" << std::endl;
}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string name, short grade) : _Name(name), _Grade(grade) {

	std::cout << "Parameter constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const & to_copy) : _Name(to_copy._Name), _Grade(to_copy._Grade) {

	std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat () {

	std::cout << "Destructor called" << std::endl;
}

// Copy assignment Operator overload
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src) {
		// this->_Name = src.getName(); //can't do that since the _Name is const
		this->_Grade = src._Grade;
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

