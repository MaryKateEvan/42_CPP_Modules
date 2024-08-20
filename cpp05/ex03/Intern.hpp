/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 11:14:18 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

	private:
	
		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyForm(const std::string& target);
		AForm* createPresidentialForm(const std::string& target);
	
	public:

		// Orthodox Canonical Form elements:
		Intern();								// default constructor
		Intern(Intern const & to_copy);			// copy constructor
		~Intern();								// destructor
		Intern& operator=(Intern const & src);	// Assignment operator overload

		// custom exception for wrong Form name given by user:
		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};

		// Function to create the form based on the given name and target
		AForm* makeForm(const std::string& formName, const std::string& target);
};

// type alias for a pointer to a member function that takes the `target` and returns an AForm*
typedef AForm* (Intern::*FormCreationFunction)(const std::string&);

// struct to hold the form type name and the function pointer to create the form
struct FormType {

	std::string name;
	FormCreationFunction creationFunction;
};

#endif // INTERN_HPP