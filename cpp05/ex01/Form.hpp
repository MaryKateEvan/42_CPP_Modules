/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:31:31 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/02 15:28:11 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
# define GRAY(text) "\033[90m" << text << "\033[0m"
# define LGRAY(text) "\033[37m" << text << "\033[0m" // Often referred to as white in terminal settings
# define RED(text) "\033[31m" << text << "\033[0m"
# define CYAN(text) "\033[1;96m" << text << "\033[0m"

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

		// custom excpetion classes, as subclasses of the Form
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
};

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Form const & b);

#endif //FORM_HPP