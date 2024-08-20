/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 04:25:01 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color

typedef void (*RunTest)();

static void waitForEnter() {
	
	if (COMMENTS)
		std::cout << DARK_GREY("\nPress " << BOLD("Enter")) << DARK_GREY(" to move to next test...");
	else
		std::cout << DARK_GREY("Press " << BOLD("Enter")) << DARK_GREY(" to move to next test...");
	
	std::cin.get();  // Waits for the user to press Enter
}


static void handleExceptions(RunTest testCase) {

	try {
		testCase();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const AForm::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const AForm::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
}

static void test1() {

	Bureaucrat mk("Mary Kate", 20);
	ShrubberyCreationForm SCF("Home");
	RobotomyRequestForm RRF("Wall-e");
	PresidentialPardonForm PPF("Marvin");
	
	std::cout << std::endl << mk << PPF << RRF << SCF << std::endl;

}

static void test2() {

	Bureaucrat mk("Mary Kate", 24);
	ShrubberyCreationForm SCF("Home");
	RobotomyRequestForm RRF("Wall-e");
	PresidentialPardonForm PPF("Marvin");
	
	std::cout << std::endl << mk << std::endl;

	mk.signForm(PPF);
	mk.signForm(RRF);
	mk.signForm(SCF);
	std::cout << PPF << RRF << SCF << std::endl;

	Bureaucrat bob("Bob", 5);
	Bureaucrat tom("Tom", 42);
	Bureaucrat todd("Todd", 135);

	std::cout << bob << tom << todd << std::endl;

	bob.executeForm(PPF);
	std::cout << std::endl;
	
	tom.executeForm(RRF);
	std::cout << std::endl;
	
	todd.executeForm(SCF);
	std::cout << std::endl;

}

static void test3() {

	Bureaucrat mk("Mary Kate", 2);
	ShrubberyCreationForm SCF("Home");
	RobotomyRequestForm RRF("Wall-e");
	PresidentialPardonForm PPF("Marvin");

	mk.signForm(PPF);
	mk.signForm(RRF);
	mk.signForm(SCF);
	std::cout << std::endl << mk << PPF << RRF << SCF << std::endl;

	Bureaucrat b("Bob", 6);
	Bureaucrat t("Tom", 50);
	Bureaucrat c("Todd", 140);

	std::cout << b << t << c << std::endl;

	b.executeForm(PPF);
	t.executeForm(RRF);
	c.executeForm(SCF);
	std::cout << std::endl;
	
}

static void test4() {

	Bureaucrat mk("Mary Kate", 60);
	ShrubberyCreationForm SCF("Rose");
	RobotomyRequestForm RRF("Wall-e");
	PresidentialPardonForm PPF("Marvin");

	// mk.signForm(PPF);
	mk.signForm(SCF);
	mk.signForm(RRF);

	Bureaucrat b("Bob", 4);
	std::cout << std::endl << mk << PPF << RRF << SCF << std::endl;
	std::cout << b << std::endl;

	b.executeForm(PPF);
	std::cout << std::endl;

	b.executeForm(RRF);
	std::cout << std::endl;
	
	b.executeForm(SCF);
	std::cout << std::endl;
}

static void test5() {

	Bureaucrat mk("Mary Kate", 150);
	ShrubberyCreationForm SCF("Autumn");
	RobotomyRequestForm RRF("Wall-e");
	PresidentialPardonForm PPF("Marvin");

	std::cout << std::endl << mk << std::endl;

	mk.signForm(PPF);
	mk.signForm(RRF);
	mk.signForm(SCF);
	
	std::cout << PPF << RRF << SCF << std::endl;

	Bureaucrat b("Bob", 5);
	Bureaucrat t("Tom", 45);
	Bureaucrat c("Todd", 137);

	std::cout << b << t << c << std::endl;

	b.executeForm(PPF);
	t.executeForm(RRF);
	c.executeForm(SCF);
	std::cout << std::endl;
	
}

int main() {
	
	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("          TEST 1️⃣ : Instantiating Different Forms         ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test1);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("       TEST 2️⃣ : Executing all three different forms         ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test2);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     TEST 3️⃣ : Form can be signed but not executed       ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test3);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     TEST 4️⃣ : Trying to execute a non-signed form       ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test4);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     TEST 5️⃣ : Form can not be signed neither executed       ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test5);

	return 0;
}
