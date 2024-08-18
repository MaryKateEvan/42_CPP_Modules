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

	std::cout << GRAY("🔨 Default constructor for AForm called") << std::endl;
}

// Parameter constructor
AForm::AForm(std::string name, short gradeToSign, short gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	std::cout << GRAY("🔨 Parameter constructor for " << name << " called") << std::endl;
	checkGradeRange(gradeToSign);
	checkGradeRange(gradeToExecute);
}

// Copy constructor
AForm::AForm(AForm const & to_copy) 
	: _name(to_copy._name), _isSigned(false), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute) {

	std::cout << GRAY("🔨 Copy constructor for AForm called") << std::endl;
}

// Destructor
AForm::~AForm () {

	std::cout << GRAY("🧹 Destructor for AForm called") << std::endl;
}

// Copy assignment Operator overload
AForm& AForm::operator=(AForm const & src) {

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
	return "Form grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is NOT signed yet to be executed!";
}

//member function asked from the Subject:
void AForm::beSigned(Bureaucrat & b) {
	
	if (this->_isSigned == true)
	{
		std::cout << RED("❗ This form is already signed!") << std::endl;
		std::cout << RED("   So no need for " << b.getName() << " to sign it again.") << std::endl;
		return ;
	}
	if (b.signForm(*this))
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, AForm const & b) {
	
	out << UNDERLINE("\nInAformation for Aform named \"") << BOLD_UNDERLINE(b.getName()) << UNDERLINE("\":") << std::endl;
	out << "- Grade required to Sign it: " << b.getGradeToSign() << std::endl;
	out << "- Grade required to Execute it: " << b.getGradeToExecute() << std::endl;
	if (b.getIsSigned() == true)
		out << "- This AForm is signed. ✅ \n" << std::endl;
	else
		out << "- This AForm is NOT signed yet. ❌ \n" << std::endl;
	return out;
}