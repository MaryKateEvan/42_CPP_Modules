/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 12:02:51 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color

int main() {
	
	std::cout << CYAN("\n----------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("          Testing the Performance of Interns      ")) << std::endl;
	std::cout << CYAN("----------------------------------------------------------") << std::endl;

	try {
		Intern someRandomIntern; //calls default constructor

		// A. Valid Form Names:

		std::cout << "\nAssigning our Intern to make a " << BOLD("\"shrubbery creation\"") << " form:" << std::endl;
		AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "plant");
		std::cout << std::endl;

		std::cout << "Assigning our Intern to make a " << BOLD("\"Robotomy Request\"") << " form:" << std::endl;
		AForm* form2 = someRandomIntern.makeForm("Robotomy Request", "wall-e");
		std::cout << std::endl;

		std::cout << "Assigning our Intern to make a " << BOLD("\"PRESIDENTIAL PARDON\"") << " form:" << std::endl;
		AForm* form3 = someRandomIntern.makeForm("PRESIDENTIAL PARDON", "Trump");
		std::cout << std::endl;

		// B. Invalid Form Names:
		std::cout << "Assigning our Intern to make an " << BOLD("\"unknown form\"") << " :" << std::endl;
		AForm* form4 = someRandomIntern.makeForm("unknown form", "some target");
		
		delete form1;
		delete form2;
		delete form3;
		delete form4;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl << std::endl;
	}

	return 0;
}
