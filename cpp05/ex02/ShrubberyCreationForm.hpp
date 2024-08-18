/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 19:38:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

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
		
		// Getters for the two private variables:
		std::string getTarget() const;

		// Execute the form
		void execute(Bureaucrat const & executor) const;

		// // custom exception class
		// class FileNotOpenedException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw(); //override of the what() method
		// };
};

#endif // SHRUBBERYCREATIONFORM_HPP