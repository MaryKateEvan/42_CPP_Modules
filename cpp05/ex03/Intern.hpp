/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 10:22:06 by mevangel         ###   ########.fr       */
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
	
		
	
	public:

		// Orthodox Canonical Form elements:
		Intern();								// default constructor
		Intern(Intern const & to_copy);			// copy constructor
		~Intern();								// destructor
		Intern& operator=(Intern const & src);	// Assignment operator overload

		
		AForm* makeForm(std::string formName, std::string target);
};

#endif // INTERN_HPP