/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define Brain_MSG(text) "🧠 \033[0;33m" << text << " for Brain called" << "\033[0m"

// Default constructor
Brain::Brain() {
		
	std::cout << Brain_MSG("Default constructor") << std::endl;
}

// Copy constructor
Brain::Brain(Brain const & to_copy) {

	std::cout << Brain_MSG("Copy constructor") << std::endl;
	*this = to_copy; //it calls the below copy assignment operator overload
}

// Destructor
Brain::~Brain () {

	std::cout << Brain_MSG("Destructor") << std::endl;
}

// Copy assignment Operator overload
Brain& Brain::operator=(Brain const & src) {

	std::cout << Brain_MSG("Copy assignment operator") << std::endl;

	for (int i = 0; i < 100; i++) {
		if (this->ideas[i] != src.ideas[i]) {
			this->ideas[i] = src.ideas[i]; // "Deep copy" for each string
		}
	}
	return *this;
}

/*
*	Adds a new string "idea" in the first available (empty) element of the array ideas[100]. So maximum capacity is 100 strings.
*/
void Brain::newIdea(std::string & idea) {

	for (int i = 0; i < 100; i++) {
		if (this->ideas[i].empty() == true) {
			this->ideas[i] = idea;
			break ;
		}
	}
}

void Brain::printCollectedIdeas() const {

	for (int i = 0; i < 100; i++) {
		if (this->ideas[i].empty() == false) {
			std::cout << "Idea no." << i + 1 << ": " << this->ideas[i] << std::endl;
		}
	}
}
