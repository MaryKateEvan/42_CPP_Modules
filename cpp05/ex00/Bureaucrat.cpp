/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/31 10:27:12 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _Name("unknown"), _Grade(150) {

	std::cout << "Default constructor called" << std::endl;
}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string name, short grade) : _Name(name), _Grade(grade) {

	std::cout << "Parameter constructor called" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
		
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

// // EXCEPTIONS:

// Bureaucrat::GradeTooHighException() {
	
	
// }

// Bureaucrat::GradeTooLowException() {

	
// }

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b) {
	
	out << "Bureaucrat " << b.getName() << " has grade " << b.getGrade() << std::endl;
	return out;
}