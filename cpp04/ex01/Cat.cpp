/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 17:39:35 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CAT_MSG(text) "🐈 \033[35m" << text << " for Cat called" << "\033[0m"

// Default constructor
Cat::Cat() : Animal() {
		
	std::cout << CAT_MSG("Default constructor") << std::endl;
	this->type = "Cat";
	this->_catBrain = new Brain();
}

// Copy constructor
Cat::Cat(Cat const & to_copy) : Animal(to_copy) {

	std::cout << CAT_MSG("Copy constructor") << std::endl;
	this->_catBrain = new Brain(*(to_copy._catBrain)); //the copy constructor takes a reference, so i need to dereference my brain pointer
}

// Destructor
Cat::~Cat () {

	delete _catBrain; // calls the destructor of Brain
	std::cout << CAT_MSG("destructor") << std::endl;
}

// Copy assignment Operator overload
Cat& Cat::operator=(Cat const & src) {

	std::cout << CAT_MSG("Copy assignment operator") << std::endl;

	if (this != &src) {
		Animal::operator=(src); //this calls the: this->type = src.type;
		*_catBrain = *(src._catBrain); //this is the correct because I want a "deep copy"!!
		// _catBrain = src._catBrain; -> if I would do this, it would be a "shallow copy" and whatever changes i would do in the one cat object would affect the other too.
	}
	return *this;
}

// Cat implementation of the virtual method.
void Cat::makeSound() const {

	std::cout << "🔊: 🐈 \033[35m" << BOLD("Meow... meeeeeow...") << "\033[0m 🔊" << std::endl;
}

/*
*	Adds a new idea in the Cat's Brain, which can fit up to 100 ideas!
*/
void Cat::hasNewIdea(std::string & new_idea) {

	this->_catBrain->newIdea(new_idea);
}