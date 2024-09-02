/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:32 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/02 15:45:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype> //for the std::isprint

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

class ScalarConverter {
	
	private:

		ScalarConverter(); //private default constructor cause we don't want the Class to be instanciablee

	public:

		ScalarConverter(ScalarConverter const & to_copy);			// copy constructor
		~ScalarConverter();											// destructor
		ScalarConverter& operator=(ScalarConverter const & src);	// Assignment operator overload
		
		//the method asked form the subject:
		static void convert(const std::string& input); //static method so it belongs to the class itself rather than separate instances/objects.
};

#endif //SCALARCONVERTER_HPP