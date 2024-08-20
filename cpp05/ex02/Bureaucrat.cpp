/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/20 04:22:17 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _Name("unknown"), _Grade(150) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for Bureaucrat called") << std::endl;
}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string name, short grade) : _Name(name), _Grade(grade) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Parameter constructor for Bureaucrat " << name << " called") << std::endl;
	checkGradeRange(grade);
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const & to_copy) : _Name(to_copy._Name), _Grade(to_copy._Grade) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for Bureaucrat called") << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for Bureaucrat called") << std::endl;
}

// Copy assignment Operator overload
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for Bureaucrat called") << std::endl;

	if (this != &src) {
		// this->_Name = src.getName(); // I can't do that since the _Name is const
		this->_Grade = src._Grade;
	}
	return *this;
}

// GETTERS for the private attributes:
std::string Bureaucrat::getName() const {
	return this->_Name;
}
short Bureaucrat::getGrade() const {
	return this->_Grade;
}

// Function to check the range of the bureaucrat's grade and throw the proper exception
void Bureaucrat::checkGradeRange(short grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Modification of the Grade:
void Bureaucrat::incrementGrade() {
	this->_Grade--;
	checkGradeRange(this->_Grade);
}
void Bureaucrat::decrementGrade() {
	this->_Grade++;
	checkGradeRange(this->_Grade);
}

// Override of the what method in the two custom exceptions:
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low!";
}

//additional member function required in ex01:
void Bureaucrat::signForm(AForm & f) const {
	
	try {
		f.beSigned(*this);
		std::cout << "🖋️  " << GREEN(_Name << " signed " << f.getName()) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "🚫🖋️  " << RED(_Name << " could not sign " << f.getName() << " because " << std::endl;
		std::cout << "     " << UNDERLINE(e.what())) << std::endl;
	}
}

//additional member function required in ex02:
void Bureaucrat::executeForm(AForm & form) const {
	
	try {
		form.execute(*this);
		std::cout << "🚀 " << YELLOW(_Name << " executed " << form.getName()) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "🚫🚀 " << RED(_Name << " could not execute " << form.getName() << " because " << std::endl;
		std::cout << "     " << UNDERLINE(e.what())) << std::endl;
	}
}

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Bureaucrat const & b) {
	
	out << BOLD(b.getName()) << ": bureaucrat grade " << BOLD(b.getGrade()) << std::endl;
	return out;
}