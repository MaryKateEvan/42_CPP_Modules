/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:58:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 03:02:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5), _target("default") {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for PresidentialPardonForm called") << std::endl;
}

// Parameter constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Parameter constructor for PresidentialPardonForm called") << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & to_copy)
	: AForm(to_copy), // Calls the base class' copy constructor
		_target(to_copy._target) { // Copies also the `target` from the object `to_copy`

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for PresidentialPardonForm called") << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for PresidentialPardonForm called") << std::endl;
}

// Copy assignment Operator overload
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for PresidentialPardonForm called") << std::endl;

	if (this != &src) {
		AForm::operator=(src); // Assigns the base class' part
		this->_target = src._target; // Assigns the `target` part of the `src` object to the current object
	}
	return *this;
}

// GETTER for the private attribute:
std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

// Execute the form
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	checkIfCanBeExecuted(executor);
	std::cout << BOLD("🕊️  " << _target << " has been pardoned by Zafod Beeblebrox.") << std::endl;
}