/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:27:32 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 15:58:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype> //for the std::isprint
# include <sstream> //for the std::istringstream
# include <limits> // for the std::numeric_limits
# include <iomanip> // for the std::fixed and std::setprecision

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
# define GRAY(text) "\033[90m" << text << "\033[0m"
# define RED(text) "\033[31m" << text << "\033[0m"
# define CYAN(text) "\033[1;96m" << text << "\033[0m"

class ScalarConverter {
	
	private:

		ScalarConverter(); //private default constructor cause we don't want the Class to be instanciablee

		//helper private methods for the convert:
		static std::string findType(std::string arg);
		// static bool displayCharConversion(const std::string& arg);
	
		static void inputIsChar(const char& c);
		static void inputIsInt(const int& num_int);
		static void inputIsFloat(const float& num_float);
		static void inputIsDouble(const double& num_double);
		// static void inputIsPseudo(const std::string& arg, bool is_float);
	
	public:

		ScalarConverter(ScalarConverter const & to_copy);			// copy constructor
		~ScalarConverter();											// destructor
		ScalarConverter& operator=(ScalarConverter const & src);	// Assignment operator overload
		
		//the method asked form the subject:
		static void convert(const std::string& arg); //static method so it belongs to the class itself rather than separate instances/objects.
};

#endif //SCALARCONVERTER_HPP