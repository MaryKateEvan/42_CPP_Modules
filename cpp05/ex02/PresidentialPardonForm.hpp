/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 19:40:27 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:
	
		std::string _target;
	
	public:

		// Orthodox Canonical Aform elements:
		PresidentialPardonForm();												// default constructor
		PresidentialPardonForm(PresidentialPardonForm const & to_copy);			// copy constructor
		~PresidentialPardonForm();												// destructor
		PresidentialPardonForm& operator=(PresidentialPardonForm const & src);	// Assignment operator overload

		// Parameter constructor
		PresidentialPardonForm(std::string target);
		
		// Getter for the private attribute:
		std::string getTarget() const;

		// Execute the form
		void execute(Bureaucrat const & executor) const;

		// // custom exception class
		// class FileNotOpenedException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw(); //override of the what() method
		// };
};

#endif // PRESIDENTIALPARDONFORM_HPP