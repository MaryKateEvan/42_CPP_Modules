/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 03:58:44 by mevangel         ###   ########.fr       */
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

	// "Makes some drilling noises":
	std::cout << BOLD("🛠️🔩🌀 Grrrrr.... Vrrrrr... Bzzzz... 🛠️🔩🌀") << std::endl;

	srand(time(NULL)); // sets the seed for rand() using the current time (in seconds), to ensure the seed and randominsing is diferrent every time the program runs
	
	// 50% randomised chance of success:
	if (rand() % 2 == 0) {
		std::cout << BOLD("🤖 👍 " << _target << " has been robotomized successfully.") << std::endl;
	}
	else {
		std::cout << BOLD("🤖 👎 " << "The robotomy of " << _target << " has failed.") << std::endl;
	}
}
