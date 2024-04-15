/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:09:59 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/15 16:47:19 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

//TODO: okay it works now, but should i check if the user doesn't give something valid?
//also the pdf says "Once all the fields have been completed, add the contact to the phonebook"
void Contact::setContactDetails() {
	
	std::cout << "Enter First name: ";
	std::getline(std::cin, this->_firstName);

	std::cout << "Enter Last name: ";
	std::getline(std::cin, this->_lastName);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, this->_nickname);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, this->_phoneNumber);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->_darkestSecret);

	std::cout << "Contact saved in PhoneBook!" << std::endl;
}

// Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret) {
	
// 	_firstName = first_name;
// 	_lastName = last_name;
// 	_nickname = nickname;
// 	_phoneNumber = phone;
// 	_darkestSecret = secret;
// }



