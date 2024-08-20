/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:17:22 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 12:07:43 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern() {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for Intern called") << std::endl;
}

// Copy constructor
Intern::Intern(Intern const & to_copy) {

	(void)to_copy; // no attributes present to be copied

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for Intern called") << std::endl;
}

// Destructor
Intern::~Intern () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for Intern called") << std::endl;
}

// Copy assignment Operator overload
Intern& Intern::operator=(Intern const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for Intern called") << std::endl;

	(void)src; // no attributes to be assigned

	return *this;
}

// custom exception for wrong Form name given by user:
const char* Intern::UnknownFormException::what() const throw() {
	return "form name is not recognized!";
}

// The three functions to create the 3 types of forms:
// They return a new, dynamically allocated, instance of the corresponding form.
AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// THE MAIN JOB OF THE INTERN:
// Creates the form based on the formName and target, returning a pointer to the created 
// form or handling the case where the form name is invalid by printing an error message.
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {

	FormType forms[] = {
		{"shrubbery creation", &Intern::createShrubberyForm},
		{"Shrubbery Creation", &Intern::createShrubberyForm},
		{"SHRUBBERY CREATION", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"Robotomy Request", &Intern::createRobotomyForm},
		{"ROBOTOMY REQUEST", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm},
		{"Presidential Pardon", &Intern::createPresidentialForm},
		{"PRESIDENTIAL PARDON", &Intern::createPresidentialForm}
	};

	std::string lowerCaseFormName = formName; // Creates a copy of `formName`
	for (std::string::size_type i = 0; i < lowerCaseFormName.length(); ++i) {
		lowerCaseFormName[i] = std::tolower(lowerCaseFormName[i]); // Converts the copy to lowercase
	}

	for (int i = 0; i < 9; ++i) {
		if (forms[i].name == formName) {
			std::cout << GREEN("📄 Intern creates " << lowerCaseFormName) << std::endl;
			return (this->*(forms[i].creationFunction))(target);
		}
	}

	// if the form's name that the user gave is not one of the above 9, throw an exception
	throw Intern::UnknownFormException();
}
