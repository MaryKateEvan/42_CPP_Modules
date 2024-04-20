/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:09:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 23:23:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
*	@param input: the string that the function checks if is valid.
*	@param type: if "alpha", the function accepts alphabetical characters and spaces.
*				 if "digit", the function accepts only digits and the '+' sign if
*							 it's the first character of the "input"
*				 if "all", the function accepts all printable ascii characters.
*	@returns true, if the "input" string is valid, or
*			 false, if the "input" string is invalid (including the case of spaces only).
*/
static bool InputIsValid(std::string input, std::string type) {

	if (input.empty() == true)
		return false;

	bool not_empty = false;
	for (int i = 0; input[i]; i++) {

		if (input[i] != ' ')
			not_empty = true;
		if (type == "alpha" && !(std::isalpha(input[i]) || input[i] == ' '))
			return false;
		else if (type == "digit") {
			if (i == 0 && !(std::isdigit(input[i]) || input[i] == '+'))
				return false;
			else if (i >= 1 && !std::isdigit(input[i]))
				return false;
		}
		else if (type == "all" && (input[i] < ' ' || input[i] > '~'))
			return false;
	}
	if (!not_empty)
		return false;
	return true;
}

/*
*	Loops until the user gives a valid "wanted info" of "type".
*	@param wanted_info: determines if the function should check for a valid First Name, 
*						Last Name, Nickname, phone number or darkest secret.
*	@param type: "alpha" if wanted_info is First name, or last name or nickname.
*				 "digit" if wanted_info is Phone number.
*				 "all" if wanted_info is Darkest Secret.
*	@returns the checked, valid input that the user gave.
*/
static std::string receiveInputFor(std::string wanted_info, std::string type) {
	
	std::string input;

	std::cout << "\033[1m" << "Enter " << wanted_info << "\033[0m" << ": ";
	if (!std::getline(std::cin, input) && std::cin.eof())
		exit(2);
	
	while (InputIsValid(input, type) == false) {
		std::cout << "Not a valid " << wanted_info << ". Please try again." << std::endl;
		std::cout << "\033[1m" << "Enter " << wanted_info << "\033[0m" << ": ";
		if (!std::getline(std::cin, input) && std::cin.eof())
			exit(2);
	}
	return input;
}

/*
*	It truncates strings longer than 10 characters, replacing the last displayable 
*	character must be replaced by a dot (’.’)
*	@param the string to be cut if it's longer than 10 characters.
*	@returns the modified (or not) string.
*/
static std::string cut_string(std::string str) {

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return str;
}

// Constructor
Contact::Contact() {}

// Destructor
Contact::~Contact() {}

/*
*	Prompts the user for a valid input to assign in each of the 5 contact details (first name,
*	last name, nickname, phone number and darkest secret) and saves also the index of the contact.
*/
void Contact::setContactDetails(short idx) {
	
	this->index = idx;

	this->_firstName = receiveInputFor("First Name", "alpha");
	this->_lastName = receiveInputFor("Last Name", "alpha");
	this->_nickname = receiveInputFor("Nickname", "alpha");
	this->_phoneNumber = receiveInputFor("Phone Number", "digit");
	this->_darkestSecret = receiveInputFor("Darkest Secret", "all");

	std::cout << IN_GREEN("Contact saved in PhoneBook!") << std::endl;
}

/*
*	Displays the corresponding, for the current Contact object, details (index, 
*	first name, last name and nickname), that appear in each row of the "Search Board".
*	Example: |        2 | Mary Kate|Evangelid.|        mk|
*/
void Contact::displayLineForSearch() const {

	std::cout << "|        " << index + 1 << " |";
	std::cout << std::setw(10) << cut_string(_firstName) << "|";
	std::cout << std::setw(10) << cut_string(_lastName) << "|";
	std::cout << std::setw(10) << cut_string(_nickname) << "|" << std::endl;
}

/*
*	Displays all 5 attributes of the current Contact Object, one field per line.
*/
void Contact::displayAllInfo() const {

	std::cout << UNDERLINE("First Name") << ": " << _firstName << std::endl;
	std::cout << UNDERLINE("Last Name") << ": " << _lastName << std::endl;
	std::cout << UNDERLINE("Nickname") << ": " << _nickname << std::endl;
	std::cout << UNDERLINE("Phone Number") << ": " << _phoneNumber << std::endl;
	std::cout << UNDERLINE("Darkest Secret") << ": " << _darkestSecret << std::endl;
}
