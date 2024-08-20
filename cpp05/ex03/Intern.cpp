/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:17:22 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 10:26:24 by mevangel         ###   ########.fr       */
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

AForm* Intern::makeForm(std::string formName, std::string target) {}