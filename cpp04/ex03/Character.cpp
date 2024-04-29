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
Character::Character(std::string const & name) : _Name(name) {

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


// THE PURE VIRTUAL FUNCTIONS THAT THE INTERFACE ICHARACTER EXPECTS THE CLASS CHARACTER TO PROVIDE:

std::string const & Character::getName() const {

	return this->_Name;
}

/*
*	Receives a dynamically allocated object Materia that places in the first available 
*	spot in the Inventory. If the Inventory is full it discards the Materia
*/
void Character::equip(AMateria* m) {

	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->_Inventory[i] == NULL) { // --> empty place in _Inventory, available to place the new Materia
			this->_Inventory[i] = m;
			std::cout << "Materia " << m->getType() << " is now equipped." << std::endl;
			return ;
		}
	}
	delete m;
	std::cout << "No space left in the Inventory" << std::endl;
}

void Character::unequip(int idx) {

	if (0 <= idx && idx < 4 && _Inventory[idx]) {
		std::cout << "Materia " << this->_Inventory[idx]->getType() << " with index " << idx << " is now unequipped." << std::endl;
		delete this->_Inventory[idx];
		this->_Inventory[idx] = NULL;
	}
	else
		std::cout << "idx " << idx << " is out of range or there's nothing there" << std::endl;
}

/*
*	"The use(int, ICharacter&) member function will have to use the Materia at the
*	slot[idx], and pass the target parameter to the AMateria::use function."
*/
void Character::use(int idx, ICharacter& target) {

	if (0 <= idx && idx < 4 && _Inventory[idx])
		_Inventory[idx]->use(target);
	else
		std::cout << "idx " << idx << " is out of range or there's nothing there" << std::endl;
}
