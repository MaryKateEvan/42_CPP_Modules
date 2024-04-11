/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:25:00 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/11 07:56:34 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

//TODO: I should always use initialization list he said on the video. 
//TODO: And he wants this syntax for the constructor: 
//TODO: Sample::Sample( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3)

PhoneBook::PhoneBook(void) {
	
	std::cout << "Constructor called" << std::endl;

	this->hi = 42; //"this" is a pointer to the current instance of the class
	
	return ;
}

PhoneBook::~PhoneBook(void) {
	
	std::cout << "Destructor called" << std::endl;
	
	return ;
}