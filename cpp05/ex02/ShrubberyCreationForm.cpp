/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 19:37:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), _target("default") {

	std::cout << GRAY("🔨 Default constructor for ShrubberyCreationForm called") << std::endl;
}

// Parameter constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {

	std::cout << GRAY("🔨 Parameter constructor for ShrubberyCreationForm called") << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & to_copy)
	: AForm(to_copy), // Calls the base class' copy constructor
		_target(to_copy._target) { // Copies also the `target` from the object `to_copy`

	std::cout << GRAY("🔨 Copy constructor for ShrubberyCreationForm called") << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm () {

	std::cout << GRAY("🧹 Destructor for ShrubberyCreationForm called") << std::endl;
}

// Copy assignment Operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {

	std::cout << GRAY("⚙️⚙️ Assignment operator for ShrubberyCreationForm called") << std::endl;

	if (this != &src) {
		AForm::operator=(src); // Assigns the base class' part
		this->_target = src._target; // Assigns the `target` part of the `src` object to the current object
	}
	return *this;
}

// GETTERS for the private attributes:
std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}