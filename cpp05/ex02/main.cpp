/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 18:49:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	catch (const AForm::GradeTooHighException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const AForm::GradeTooLowException& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
}

static void test1() {

	Bureaucrat mk("Mary Kate", 42);
	AForm f("Report", 100, 150);

	std::cout << std::endl << mk << f ;
}

static void test2() {

	AForm f1("AForm1", 100, 150); // valid
	AForm f2("AForm2", 0, 150); // too high gradeToSign
	AForm f3("AForm3", 100, 151); // too low gradeToExecute
	AForm f4("AForm4", 0, 151); // both out of range
	
	std::cout << f1 << f2 << f3 << f4;
}

static void test3() {

	Bureaucrat mk("Mary Kate", 42);
	AForm f("Report", 100, 150);

	std::cout << std::endl << mk << f;

	f.beSigned(mk);
	
	std::cout << f;
}

static void test4() {

	Bureaucrat a("Anna", 101);
	AForm f("Manuscript", 100, 150);

	std::cout << std::endl << a << f;

	f.beSigned(a);
	
	std::cout << f;
}

static void test5() {

	Bureaucrat mk("Mary Kate", 42);
	AForm f("Report", 100, 150);

	std::cout << std::endl << mk << std::endl;
	f.beSigned(mk);
	std::cout << f;

	// New bureaucrat to try sign the same Aform:
	Bureaucrat b("Bob", 1);
	std::cout << std::endl << b << std::endl;
	
	f.beSigned(b);
	
	std::cout << f;
}

int main() {
	
	std::cout << CYAN(BOLD("\nTEST 1️⃣ : Bureaucrats and AForms with valid grades")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test1);

	std::cout << CYAN(BOLD("\nTEST 2️⃣ : Invalid AForm Grades")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test2);

	std::cout << CYAN(BOLD("\nTEST 3️⃣ : Bureaucrat can sign the AForm ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test3);

	std::cout << CYAN(BOLD("\nTEST 4️⃣ : Bureaucrat can NOT sign the AForm ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test4);

	std::cout << CYAN(BOLD("\nTEST 5️⃣ : AForm is already Signed ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	handleExceptions(test5);

	return 0;
}
