/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:31:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 00:47:48 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Form {

	private:
	
		const std::string _name;
		bool _isSigned;
		const short _gradeToSign;
		const short _gradeToExecute;
		void checkGradeRange(short grade) const;
	
	public:

		// Orthodox Canonical form elements:
		Form();								// default constructor
		Form(Form const & to_copy);			// copy constructor
		~Form();							// destructor
		Form& operator=(Form const & src);	// Assignment operator overload

		// Parameter constructor
		Form(std::string name, short gradeToSign, short gradeToExecute);
		
		// Getters for the two private variables:
		std::string getName() const;
		short getGradeToSign() const;
		short getGradeToExecute() const;
		bool getIsSigned() const;

		// custom exception classes, as subclasses of the Form
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

		//member function asked from the Subject:
		// void beSigned(Bureaucrat & b);
		void beSigned(Bureaucrat const & b);
};

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Form const & b);

#endif //FORM_HPP