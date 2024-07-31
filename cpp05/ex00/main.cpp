/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/31 13:22:06 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	
	{
	std::cout << BOLD("\nTEST 1: Constructing bureaucrats with valid grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat a;
		Bureaucrat mk("Mary Kate", 42);	//valid
		Bureaucrat t("Tom", 100);
		Bureaucrat copy(mk); //for copy constructor call

		std::cout << a << mk << copy;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
	}

	{
	std::cout << BOLD("\nTEST 2: Modifying the grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat a;
		Bureaucrat mk("Mary Kate", 42);	//valid
		Bureaucrat t("Tom", 100);
		Bureaucrat s("Stefan", 5);

		std::cout << UNDERLINE("Initial state of our bureaucrats: ") << std::endl;
		std::cout << a << mk << t << s;
		
		mk.incrementGrade();
		t.decrementGrade();
		s = a; //for assignment operator call
		s.incrementGrade();
		std::cout << UNDERLINE("State after the grade modifications: ") << std::endl;
		std::cout << a << mk << t << s;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
	}

	{
	std::cout << BOLD("\nTEST 3: Constructing bureaucrats with ") << BOLD_UNDERLINE("invalid") << BOLD(" grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat a("Bob", 151); // too low
		Bureaucrat b("Elsa", 0); // too high
		std::cout << a << b;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
	}

	{
	std::cout << BOLD("\nTEST 4: Increment Grade to out of range ") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat a("Anna", 1); // too high
		a.incrementGrade();
		std::cout << a;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
	}

	{
	std::cout << BOLD("\nTEST 5: Decrement Grade to out of range ") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat a("Katerina", 150); // too low
		a.decrementGrade();
		std::cout << a;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
	}

	return 0;
}
