/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:09:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/16 12:31:51 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

//TODO: okay it works now, but should i check if the user doesn't give something valid?
//also the pdf says "Once all the fields have been completed, add the contact to the phonebook"
void Contact::setContactDetails(short idx) {
	
	this->index = idx;
	
	std::cout << "Enter First name: ";
	if (!std::getline(std::cin, this->_firstName) && std::cin.eof())
		std::exit(2);

	std::cout << "Enter Last name: ";
	if (!std::getline(std::cin, this->_lastName) && std::cin.eof())
		std::exit(2);

	std::cout << "Enter Nickname: ";
	if (!std::getline(std::cin, this->_nickname) && std::cin.eof())
		std::exit(2);

	std::cout << "Enter Phone Number: ";
	if (!std::getline(std::cin, this->_phoneNumber) && std::cin.eof())
		std::exit(2);

	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, this->_darkestSecret) && std::cin.eof())
		std::exit(2);

	std::cout << "Contact saved in PhoneBook!" << std::endl;
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


// Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret) {
	
// 	_firstName = first_name;
// 	_lastName = last_name;
// 	_nickname = nickname;
// 	_phoneNumber = phone;
// 	_darkestSecret = secret;
// }



