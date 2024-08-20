/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 23:41:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
	
		std::string _target;
	
	public:

		// Orthodox Canonical Aform elements:
		ShrubberyCreationForm();												// default constructor
		ShrubberyCreationForm(ShrubberyCreationForm const & to_copy);			// copy constructor
		~ShrubberyCreationForm();												// destructor
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);	// Assignment operator overload

		// Parameter constructor
		ShrubberyCreationForm(std::string target);
		
		// Getter for the private attribute:
		std::string getTarget() const;

		// Execute the form
		void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP