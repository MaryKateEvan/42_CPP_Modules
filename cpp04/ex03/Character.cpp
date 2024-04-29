/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:39:07 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character() : _Name("unknown") {

	for (int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
	// Initialization of the inventory as NULL so that it can be recognized if there are slots left
}

//string parameter constructor that assigns the passed name to the private attribute of the class
Character::Character(std::string name) : _Name(name) {

	for (int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
}

// Copy constructor
Character::Character(Character const & to_copy) {

	this->_Name = to_copy._Name;
	for (int i = 0; i < 4; i++) {
		if (to_copy._Inventory[i] != NULL)
			this->_Inventory[i] = to_copy._Inventory[i]->clone();
		else
			this->_Inventory[i] = NULL;
	}
}

// Destructor
Character::~Character () {

	for (int i = 0; i < 4; i++) {
		if (this->_Inventory[i] != NULL)
			delete this->_Inventory[i];
	}
}

// Copy assignment Operator overload
Character& Character::operator=(Character const & src) {

	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->_Inventory[i] != NULL)
				delete this->_Inventory[i]; //first free the spot before you assign the new value from src
			// And then check if there is a value to assign:
			if (src._Inventory[i] != NULL)
				this->_Inventory[i] = src._Inventory[i]->clone();
			else
				this->_Inventory[i] = NULL;
		}
	}
	return *this;
}


// THE PURE VIRTUAL FUNCTIONS THAT THE INTERFACE ICHARACTER EXPECTS CHARACTER TO HAVE:

std::string const & Character::getName() const {


}

void Character::equip(AMateria* m) {


}

void Character::unequip(int idx) {


}

void Character::use(int idx, ICharacter& target) {


}
