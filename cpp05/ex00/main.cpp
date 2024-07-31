/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:37 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	catch (const std::exception& e) {
		std::cout << RED("❗ Other exception found: ") << UNDERLINE(e.what()) << std::endl;
	}
}

static void test1() {

	Bureaucrat a;
	Bureaucrat mk("Mary Kate", 42);	//valid
	Bureaucrat t("Tom", 100);
	Bureaucrat copy(mk); //for copy constructor call

	std::cout << a << mk << copy;
}

static void test2() {

	Bureaucrat a;
	Bureaucrat mk("Mary Kate", 42);	//valid
	Bureaucrat t("Tom", 100);
	Bureaucrat s("Stefan", 5);

	std::cout << UNDERLINE("Initial state of our bureaucrats: ") << std::endl;
	std::cout << mk << t << s;
	
	mk.incrementGrade();
	t.decrementGrade();
	s = a; //for assignment operator call
	s.incrementGrade();
	std::cout << UNDERLINE("State after the grade modifications: ") << std::endl;
	std::cout << mk << t << s;
}

static void test3() {

	Bureaucrat a("Bob", 151); // too low
	Bureaucrat b("Elsa", 0); // too high
	std::cout << a << b;
}

static void test4() {
	
	Bureaucrat a("Anna", 1); // too high
	a.incrementGrade();
	std::cout << a;
}

static void test5() {

	Bureaucrat a("Katerina", 150); // too low
	a.decrementGrade();
	std::cout << a;
}

int main() {
	
	std::cout << BOLD("\nTEST 1: Constructing bureaucrats with valid grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	handleExceptions(test1);

	std::cout << BOLD("\nTEST 2: Modifying the grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	handleExceptions(test2);

	std::cout << BOLD("\nTEST 3: Constructing bureaucrats with ") << BOLD_UNDERLINE("invalid") << BOLD(" grades") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	handleExceptions(test3);

	std::cout << BOLD("\nTEST 4: Increment Grade to out of range ") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	handleExceptions(test4);

	std::cout << BOLD("\nTEST 5: Decrement Grade to out of range ") << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	handleExceptions(test5);

	return 0;
}
