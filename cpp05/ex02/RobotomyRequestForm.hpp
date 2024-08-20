/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:06:58 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 19:40:27 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>  // for rand()
# include <ctime>    // for time()

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:
	
		std::string _target;
	
	public:

		// Orthodox Canonical Aform elements:
		RobotomyRequestForm();												// default constructor
		RobotomyRequestForm(RobotomyRequestForm const & to_copy);			// copy constructor
		~RobotomyRequestForm();												// destructor
		RobotomyRequestForm& operator=(RobotomyRequestForm const & src);	// Assignment operator overload

		// Parameter constructor
		RobotomyRequestForm(std::string target);
		
		// Getter for the private attribute:
		std::string getTarget() const;

		// Execute the form
		void execute(Bureaucrat const & executor) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP