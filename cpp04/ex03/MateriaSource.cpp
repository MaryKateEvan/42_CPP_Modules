/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:31:56 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/29 03:33:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor that initializes the memory of capacity 4.
MateriaSource::MateriaSource() {

	for (int i = 0; i < 4; i++) {
		this->memory[i] = NULL; //NULL because every element is a pointer to AMateria
	}
	// Initialization to NULL so that we can check if there is free space in memory (if == NULL)
}

// Copy constructor
MateriaSource::MateriaSource(MateriaSource const & to_copy) {

	for (int i = 0; i < 4; i++) {
		if (to_copy.memory[i] != NULL)
			this->memory[i] = to_copy.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
}

// Destructor
MateriaSource::~MateriaSource () {

	for (int i = 0; i < 4; i++) {
		if (this->memory[i] != NULL)
			delete this->memory[i];
	}
}

// Copy assignment Operator overload
MateriaSource& MateriaSource::operator=(MateriaSource const & src) {

	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->memory[i] != NULL)
				delete this->memory[i]; //first free the spot before you assign the new value from src
			// And then check if there is a value to assign:
			if (src.memory[i] != NULL)
				this->memory[i] = src.memory[i]->clone();
			else
				this->memory[i] = NULL;
		}
	}
	return *this;
}

/*
*	Copies the Materia passed as a parameter and stores it in memory so it can be cloned later.
*/
void MateriaSource::learnMateria(AMateria* new_mat) {

	if (new_mat == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->memory[i] == NULL) { // --> empty place in memory, available to place the new Materia
			this->memory[i] = new_mat;
			return ;
		}
	}
	// if there was no space left in memory:
	delete new_mat; //we delete the dynamically allocated AMateria object, because it can not be used
	std::cout << "No more space left in the memory of MateriaSource." << std::endl;
}


/*
*	Returns a new Materia (that's why the clone) which is a copy of a previously learned Materia
*	If the type is unknown it returns zero, which means that the Materia could not be created.
*/
AMateria* MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++) {
		if (this->memory[i] != NULL && this->memory[i]->getType() == type)
			return (this->memory[i]->clone());
	}
	std::cout << "Unknown type of Materia: " << type << ". Can not be created." << std::endl;
	return 0;
}

