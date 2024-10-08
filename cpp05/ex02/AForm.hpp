/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:31:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 18:20:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

// Form Class becomes Abstract now ("AForm"), because of the pure virtual function `execute`
// Now AForm can not be instantiated, but it can be used as a base class for other classes
class AForm {

	private:
	
		const std::string _name;
		bool _isSigned;
		const short _gradeToSign;
		const short _gradeToExecute;
		void checkGradeRange(short grade) const;
	
	public:

		// Orthodox Canonical Aform elements:
		AForm();								// default constructor
		AForm(AForm const & to_copy);			// copy constructor
		virtual ~AForm();						// virtual destructor, to ensure the derived classes' destructors are properly called
		AForm& operator=(AForm const & src);	// Assignment operator overload

		// Parameter constructor
		AForm(std::string name, short gradeToSign, short gradeToExecute);
		
		// Getters for the two private variables:
		std::string getName() const;
		short getGradeToSign() const;
		short getGradeToExecute() const;
		bool getIsSigned() const;

		// custom exception classes, as subclasses of the AForm
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class AlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};

		void beSigned(Bureaucrat const & b);

		// function for the derived classes to check if the form can be executed
		void checkIfCanBeExecuted(Bureaucrat const & executor) const;

		// Pure virtual function (making AForm an abstract class)
		virtual void execute(Bureaucrat const & executor) const = 0; //means that the derived classes MUST provide implementation for this function
};

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, AForm const & b);

#endif //AFORM_HPP