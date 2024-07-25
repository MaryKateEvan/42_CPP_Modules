/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:38:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/25 04:45:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class Bureaucrat {

	private:

		const std::string _Name;
		unsigned short _Grade;
	
	public:

		// Orthodox Canonical form elements:
		Bureaucrat();									// default constructor
		Bureaucrat(Bureaucrat const & to_copy);			// copy constructor
		~Bureaucrat();									// destructor
		Bureaucrat& operator=(Bureaucrat const & src);	// Assignment operator overload

		// Getters for the two private vaariables:
		getName();
		getGrade();

		//In order to change the grade:
		incrementGrade();
		decrementGrade();
};

#endif //BUREAUCRAT_HPP