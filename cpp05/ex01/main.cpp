/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 00:43:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

typedef void (*RunTest)();

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
	catch (const Form::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
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
	
	std::cout << CYAN(BOLD("\nTEST 1️⃣ : Bureaucrats and Forms with valid grades")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test1);

	std::cout << CYAN(BOLD("\nTEST 2️⃣ : Invalid Form Grades")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test2);

	std::cout << CYAN(BOLD("\nTEST 3️⃣ : Bureaucrat can sign the Form ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test3);

	std::cout << CYAN(BOLD("\nTEST 4️⃣ : Bureaucrat can NOT sign the Form ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test4);

	std::cout << CYAN(BOLD("\nTEST 5️⃣ : Form is already Signed ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test5);

	return 0;
}
