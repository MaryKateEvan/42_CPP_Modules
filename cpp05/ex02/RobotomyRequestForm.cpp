/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 03:02:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45), _target("default") {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for RobotomyRequestForm called") << std::endl;
}

// Parameter constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Parameter constructor for RobotomyRequestForm called") << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & to_copy)
	: AForm(to_copy), // Calls the base class' copy constructor
		_target(to_copy._target) { // Copies also the `target` from the object `to_copy`

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for RobotomyRequestForm called") << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for RobotomyRequestForm called") << std::endl;
}

// Copy assignment Operator overload
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for RobotomyRequestForm called") << std::endl;

	if (this != &src) {
		AForm::operator=(src); // Assigns the base class' part
		this->_target = src._target; // Assigns the `target` part of the `src` object to the current object
	}
	return *this;
}

// GETTER for the private attribute:
std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

// Execute the form
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	checkIfCanBeExecuted(executor);
	// std::cout << GREEN("📜 " << _target << " has been pardoned by Zafod Beeblebrox.") << std::endl;
}