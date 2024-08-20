/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 09:06:47 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), _target("default") {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for ShrubberyCreationForm called") << std::endl;
}

// Parameter constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Parameter constructor for ShrubberyCreationForm called") << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & to_copy)
	: AForm(to_copy), // Calls the base class' copy constructor
		_target(to_copy._target) { // Copies also the `target` from the object `to_copy`

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for ShrubberyCreationForm called") << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for ShrubberyCreationForm called") << std::endl;
}

// Copy assignment Operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for ShrubberyCreationForm called") << std::endl;

	if (this != &src) {
		AForm::operator=(src); // Assigns the base class' part
		this->_target = src._target; // Assigns the `target` part of the `src` object to the current object
	}
	return *this;
}

// GETTER for the private attribute:
std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

// Execute the form
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	checkIfCanBeExecuted(executor);

	std::string outputFilename = this->_target + "_shrubbery";
	std::ofstream out(outputFilename.c_str()); //c_str() converts a C++ string to a C string. (i had problem in linux without this)

    out << "	    ccee88oo\n"
        << "	  C8O8O8Q8PoOb o8oo\n"
        << "	 dOB69QO8PdUOpugoO9bD\n"
        << "	CgggbU8OU qOp qOdoUOdcb\n"
        << "	    6OuU  /p u gcoUodpP\n"
        << "	      \\\\//  /douUP\n"
        << "	        \\\\////\n"
        << "	         |||/\\\n"
        << "	         |||\\/\n"
        << "	         |||||\n"
        << "	   .....//||||\\....\n";

	out.close();

	std::cout << BOLD("🌳 Shrubbery has been created in the file: " << outputFilename) << std::endl;
}