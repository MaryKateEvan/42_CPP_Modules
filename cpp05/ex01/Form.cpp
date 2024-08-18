/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:46:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/08/19 01:29:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default constructor
Form::Form() : _name("undetermined"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {

	std::cout << GRAY("🔨 Default constructor for Form called") << std::endl;
}

// Parameter constructor
Form::Form(std::string name, short gradeToSign, short gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	std::cout << GRAY("🔨 Parameter constructor for " << name << " called") << std::endl;
	checkGradeRange(gradeToSign);
	checkGradeRange(gradeToExecute);
}

// Copy constructor
Form::Form(Form const & to_copy) 
	: _name(to_copy._name), _isSigned(false), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute) {

	std::cout << GRAY("🔨 Copy constructor for Form called") << std::endl;
}

// Destructor
Form::~Form () {

	std::cout << GRAY("🧹 Destructor for Form called") << std::endl;
}

// Copy assignment Operator overload
Form& Form::operator=(Form const & src) {

	std::cout << GRAY("⚙️⚙️ Assignment operator for Form called") << std::endl;

	if (this != &src) {
		// _name and grades can not be assigned since they are const
		this->_isSigned = src._isSigned;
	}
	return *this;
}

// GETTERS for the private attributes:
std::string Form::getName() const {
	return this->_name;
}
short Form::getGradeToSign() const {
	return this->_gradeToSign;
}
short Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}
bool Form::getIsSigned() const {
	return this->_isSigned;
}

// Function to check the range of the Form's grade and throw the proper exception
void Form::checkGradeRange(short grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Override of the what method in the two custom exceptions:
const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}
const char* Form::AlreadySignedException::what() const throw() {
	return "form is already signed!";
}

//member function asked from the Subject:
void Form::beSigned(Bureaucrat const & b) {
	
	if (this->_isSigned == true)
		throw Form::AlreadySignedException();
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Form const & b) {
	
	out << UNDERLINE("\nInformation for form named \"") << BOLD_UNDERLINE(b.getName()) << UNDERLINE("\":") << std::endl;
	out << "- Grade required to Sign it: " << b.getGradeToSign() << std::endl;
	out << "- Grade required to Execute it: " << b.getGradeToExecute() << std::endl;
	if (b.getIsSigned() == true)
		out << "- This Form is signed. ✅ \n" << std::endl;
	else
		out << "- This Form is NOT signed yet. ❌ \n" << std::endl;
	return out;
}

// the previous version of the member function beSigned:
// void Form::beSigned(Bureaucrat & b) {
	
// 	if (this->_isSigned == true)
// 	{
// 		std::cout << RED("❗ This form is already signed!") << std::endl;
// 		std::cout << RED("   So no need for " << b.getName() << " to sign it again.") << std::endl;
// 		return ;
// 	}
// 	if (b.signForm(*this))
// 		this->_isSigned = true;
// 	else
// 		throw Form::GradeTooLowException();
// }