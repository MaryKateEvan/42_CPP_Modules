/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/18 17:58:05 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("undetermined"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Default constructor for AForm called") << std::endl;
}

// Parameter constructor
AForm::AForm(std::string name, short gradeToSign, short gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Parameter constructor for AForm called") << std::endl;
	checkGradeRange(gradeToSign);
	checkGradeRange(gradeToExecute);
}

// Copy constructor
AForm::AForm(AForm const & to_copy) 
	: _name(to_copy._name), _isSigned(false), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute) {

	if (COMMENTS)
		std::cout << GRAY("🔨 Copy constructor for AForm called") << std::endl;
}

// Destructor
AForm::~AForm () {

	if (COMMENTS)
		std::cout << GRAY("🧹 Destructor for AForm called") << std::endl;
}

// Copy assignment Operator overload
AForm& AForm::operator=(AForm const & src) {

	if (COMMENTS)
		std::cout << GRAY("⚙️⚙️ Assignment operator for AForm called") << std::endl;

	if (this != &src) {
		// _name and grades can not be assigned since they are const
		this->_isSigned = src._isSigned;
	}
	return *this;
}

// GETTERS for the private attributes:
std::string AForm::getName() const {
	return this->_name;
}
short AForm::getGradeToSign() const {
	return this->_gradeToSign;
}
short AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}
bool AForm::getIsSigned() const {
	return this->_isSigned;
}

// Function to check the range of the AForm's grade and throw the proper exception
void AForm::checkGradeRange(short grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Override of the what method in the two custom exceptions:
const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}
const char* AForm::AlreadySignedException::what() const throw() {
	return "form is already signed!";
}
const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is NOT signed yet to be executed!";
}

void AForm::beSigned(Bureaucrat const & b) {
	
	if (this->_isSigned == true)
		throw AForm::AlreadySignedException();
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::checkIfCanBeExecuted(Bureaucrat const & executor) const {

	if (this->_isSigned == false) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->_gradeToExecute) {
		throw GradeTooLowException();
	}
}

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, AForm const & b) {
	
	out << UNDERLINE("\nInformation for form named \"") << BOLD_UNDERLINE(b.getName()) << UNDERLINE("\":") << std::endl;
	out << "- Grade required to Sign it: " << b.getGradeToSign() << std::endl;
	out << "- Grade required to Execute it: " << b.getGradeToExecute() << std::endl;
	if (b.getIsSigned() == true)
		out << "- This Form is signed. ✅" << std::endl;
	else
		out << "- This Form is NOT signed yet. ❌" << std::endl;
	return out;
}