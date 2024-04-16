/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:25:00 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/16 12:37:14 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//TODO: I should always use initialization list he said on the video. 
//TODO: And he wants this syntax for the constructor: 
//TODO: Sample::Sample( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3)

// constructor
PhoneBook::PhoneBook() {
	
	this->idx_to_add = 0;
	this->sum_contacts = 0;
}

//destructor
PhoneBook::~PhoneBook() {}

void PhoneBook::add(void) {
	
	if (idx_to_add == 8)
		idx_to_add = 0;

	contacts[idx_to_add].setContactDetails(idx_to_add);

	idx_to_add++; //move the index to be ready for the next addition.
	
	if (sum_contacts != 8)
		sum_contacts++; //the sum of the contacts can reach maximum 8
}

void PhoneBook::search(void) const {
	
	if (sum_contacts == 0) {
		std::cout << "No contacts yet to display and search from." << std::endl;
		std::cout << "Consider adding some first." << std::endl;
		return ;
	}

	std::cout << std::endl;
	std::cout << BOLD_UNDERLINE("|   Index  |First Name| Last Name| Nickname |") << std::endl;
	for (int i = 0; i < sum_contacts; i++) {
		contacts[i].displayLineForSearch();
	}
	std::cout << std::endl;

	std::string	input;
	std::cout << "Enter the index of the contact you want to see more: ";
	if (!std::getline(std::cin, input) && std::cin.eof())
		std::exit(2);

	short index_user_wants = (short)std::atoi(input.c_str());

	while (index_user_wants < 1 || index_user_wants > sum_contacts)
	{
		std::cout << "No contact with such index. Please try again." << std::endl;
		std::cout << "Enter the index of the contact you want to see more: ";
		if (!std::getline(std::cin, input) && std::cin.eof())
			std::exit(2);
		index_user_wants = (short)std::atoi(input.c_str());
	}
	
	std::cout << std::endl;
	std::cout << "Here's the info of Contact no." << index_user_wants << ":" << std::endl;
	contacts[index_user_wants - 1].displayAllInfo();
}
