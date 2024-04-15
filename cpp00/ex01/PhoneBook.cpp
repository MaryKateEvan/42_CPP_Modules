/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:25:00 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/15 16:51:31 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//TODO: I should always use initialization list he said on the video. 
//TODO: And he wants this syntax for the constructor: 
//TODO: Sample::Sample( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3)

// constructor declaration
PhoneBook::PhoneBook() {
	
	this->idx_to_add = 0;
}

//destructor declaration
PhoneBook::~PhoneBook() {}

void PhoneBook::add(void) {
	
	if (idx_to_add == 8)
		idx_to_add = 0;
	contacts[idx_to_add].setContactDetails();
	idx_to_add++;
}

void PhoneBook::search(void) const {
	std::cout << "Hello from add method" << std::endl;
}