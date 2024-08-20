/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 12:25:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color

int main() {
	
	std::cout << CYAN("\n----------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("          Testing the Performance of Interns      ")) << std::endl;
	std::cout << CYAN("----------------------------------------------------------") << std::endl;

	Intern someRandomIntern; //calls default constructor

	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	AForm* form4 = NULL;

	try {
		std::cout << "\nAssigning our Intern to make a " << BOLD("\"shrubbery creation\"") << " form:" << std::endl;
		form1 = someRandomIntern.makeForm("shrubbery creation", "plant");
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found while creating form1: " << UNDERLINE(e.what())) << std::endl << std::endl;
	}

	try {
		std::cout << "Assigning our Intern to make a " << BOLD("\"Robotomy Request\"") << " form:" << std::endl;
		form2 = someRandomIntern.makeForm("Robotomy Request", "wall-e");
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found while creating form2: " << UNDERLINE(e.what())) << std::endl << std::endl;
	}

	try {
		std::cout << "Assigning our Intern to make a " << BOLD("\"PRESIDENTIAL PARDON\"") << " form:" << std::endl;
		form3 = someRandomIntern.makeForm("PRESIDENTIAL PARDON", "Trump");
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found while creating form3: " << UNDERLINE(e.what())) << std::endl << std::endl;
	}

	try {
		std::cout << "Assigning our Intern to make an " << BOLD("\"unknown form\"") << " :" << std::endl;
		form4 = someRandomIntern.makeForm("unknown form", "some target");
	} catch (const std::exception& e) {
		std::cout << RED("❗ Exception found while creating form4: " << UNDERLINE(e.what())) << std::endl << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
