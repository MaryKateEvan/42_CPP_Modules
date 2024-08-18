/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:38:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 21:33:16 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
# define GRAY(text) "\033[90m" << text << "\033[0m"
# define RED(text) "\033[31m" << text << "\033[0m"
# define CYAN(text) "\033[1;96m" << text << "\033[0m"
# define GREEN(text) "\033[1;92m" << text << "\033[0m"
# define YELLOW(text) "\033[1;93m" << text << "\033[0m"

class AForm;

class Bureaucrat {

	private:

		const std::string _Name;
		short _Grade;
		void checkGradeRange(short grade) const;
	
	public:

		// Orthodox Canonical form elements:
		Bureaucrat();									// default constructor
		Bureaucrat(Bureaucrat const & to_copy);			// copy constructor
		~Bureaucrat();									// destructor
		Bureaucrat& operator=(Bureaucrat const & src);	// Assignment operator overload

		// Parameter constructor
		Bureaucrat(std::string name, short grade);
		
		// Getters for the two private variables:
		std::string getName() const;
		short getGrade() const;

		// In order to change the grade:
		void incrementGrade();
		void decrementGrade();

		// custom excpetion classes, as subclasses of the Bureaucrat
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};

		bool signForm(AForm & f) const;

		//new function asked in ex02:
		bool executeForm(AForm & f) const;
};

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Bureaucrat const & b);

#endif //BUREAUCRAT_HPP