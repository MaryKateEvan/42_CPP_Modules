/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 12:41:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color

typedef void (*RunTest)();

static void waitForEnter() {
	
	if (COMMENTS)
		std::cout << DARK_GREY("\nPress " << BOLD("Enter")) << DARK_GREY(" to move to next test... ");
	else
		std::cout << DARK_GREY("Press " << BOLD("Enter")) << DARK_GREY(" to move to next test... ");
	
	std::cin.get();  // Waits for the user to press Enter
}

static void handleExceptions(RunTest testCase) {

	try {
		testCase();
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
}

static void test1() {

	Bureaucrat mk("Mary Kate", 42);
	Form f("Report", 100, 150);

	std::cout << std::endl << mk << f ;
}

static void test2() {

	Form f1("Form1", 100, 150); // valid
	Form f2("Form2", 0, 150); // too high gradeToSign
	Form f3("Form3", 100, 151); // too low gradeToExecute
	Form f4("Form4", 0, 151); // both out of range
	
	std::cout << f1 << f2 << f3 << f4;
}

static void test3() {

	Bureaucrat mk("Mary Kate", 42);
	Form f("Report", 100, 150);

	std::cout << std::endl << mk << f;

	mk.signForm(f);
	
	std::cout << f;
}

static void test4() {

	Bureaucrat a("Anna", 101);
	Form f("Manuscript", 100, 150);

	std::cout << std::endl << a << f;

	a.signForm(f);
	// f.beSigned(a);
	
	std::cout << f;
}

static void test5() {

	Bureaucrat mk("Mary Kate", 42);
	Form f("Report", 100, 150);

	std::cout << std::endl << mk << std::endl;
	mk.signForm(f);
	std::cout << f;

	// New bureaucrat to try sign the same form:
	Bureaucrat b("Bob", 1);
	std::cout << std::endl << b << std::endl;
	
	b.signForm(f);
	
	std::cout << f;
}

int main() {
	
	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("      TEST 1️⃣ : Bureaucrats and Forms with valid grades     ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test1);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("            TEST 2️⃣ : Invalid Form Grades              ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test2);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("         TEST 3️⃣ : Bureaucrat can sign the Form           ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test3);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("     TEST 4️⃣ : Bureaucrat can NOT sign the Form       ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test4);
	waitForEnter();

	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("          TEST 5️⃣ : Form is already Signed             ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;
	handleExceptions(test5);

	return 0;
}
