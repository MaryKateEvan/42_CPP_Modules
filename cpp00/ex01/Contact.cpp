/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:09:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/16 16:18:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact() {}

// Destructor
Contact::~Contact() {}

bool Contact::InputIsValid(std::string input, std::string type) const {

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
		else if (type == "alnum" && (input[i] < ' ' || input[i] > '~'))
			return false;
	}
	if (!not_empty)
		return false;
	return true;
}

std::string Contact::receiveInputFor(std::string wanted_info, std::string type) const {
	
	std::string input;

	std::cout << "\033[1m" << "Enter " << wanted_info << "\033[0m" << ": ";
	if (!std::getline(std::cin, input) && std::cin.eof())
		std::exit(2);
	
	while (InputIsValid(input, type) == false) {
		std::cout << "Not a valid " << wanted_info << ". Please try again." << std::endl;
		std::cout << "\033[1m" << "Enter " << wanted_info << "\033[0m" << ": ";
		if (!std::getline(std::cin, input) && std::cin.eof())
			std::exit(2);
	}
	return input;
}

void Contact::setContactDetails(short idx) {
	
	this->index = idx;

	this->_firstName = receiveInputFor("First Name", "alpha");
	this->_lastName = receiveInputFor("Last Name", "alpha");
	this->_nickname = receiveInputFor("Nickname", "alpha");
	this->_phoneNumber = receiveInputFor("Phone Number", "digit");
	this->_darkestSecret = receiveInputFor("Darkest Secret", "alnum");

	std::cout << IN_GREEN("Contact saved in PhoneBook!") << std::endl;
}

std::string Contact::cut_string(std::string str) const {

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return str;
}

void Contact::displayLineForSearch() const {

	std::cout << "|        " << index + 1 << " |";
	std::cout << std::setw(10) << cut_string(_firstName) << "|";
	std::cout << std::setw(10) << cut_string(_lastName) << "|";
	std::cout << std::setw(10) << cut_string(_nickname) << "|" << std::endl;
	// std::cout << index + 1 << " | " << _firstName << " | " << _lastName << " | " << _nickname << std::endl;
}

void Contact::displayAllInfo() const {

	std::cout << UNDERLINE("First Name") << ": " << _firstName << std::endl;
	std::cout << UNDERLINE("Last Name") << ": " << _lastName << std::endl;
	std::cout << UNDERLINE("Nickname") << ": " << _nickname << std::endl;
	std::cout << UNDERLINE("Phone Number") << ": " << _phoneNumber << std::endl;
	std::cout << UNDERLINE("Darkest Secret") << ": " << _darkestSecret << std::endl;
}
