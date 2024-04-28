/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:30:39 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 19:26:30 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	// PART A: SUBTYPE POLYMORPHISM OF THE makeSound()
	std::cout << BOLD_UNDERLINE("\nTEST 1: SUBTYPE POLYMORPHISM\n") << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	// testing the inherited getType member function:
	std::cout << std::endl;
	std::cout << "Object i is of type: " << UNDERLINE(i->getType()) << std::endl;
	std::cout << "Object j is of type: " << UNDERLINE(j->getType()) << std::endl;
	std::cout << std::endl;
	
	// testing the overriden makeSound method:
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;

	// PART B: THE REQUEST FORM THE SUBJECT WHILE LOOP
	std::cout << BOLD_UNDERLINE("\nTEST 2: THE REQUESTED FROM THE SUBJECT WHILE LOOP:\n") << std::endl;

	Animal* animals[8];

	std::cout << UNDERLINE("a) Half of the objects are constructed as Dogs:") << std::endl;
	for (int i = 0; i < 4; i++) {
		animals[i] = new Dog();
	}
	std::cout << UNDERLINE("\nb) And the rest half are constructed as Cats:") << std::endl;
	for (int i = 4; i < 8; i++) {
		animals[i] = new Cat();
	}
	std::cout << UNDERLINE("\nDestruction of all, directly, as Animals:") << std::endl;
	for (int i = 0; i < 8; i++) {
		delete animals[i];
	}

	// // PART B: TESTING THE CONSTRUCTION OF THE BRAIN CLASS:
	// {
	// std::cout << BOLD_UNDERLINE("\nTEST 3: BRAIN 🧠 CONSTRUCTION\n") << std::endl;

	// Brain brain1;
	// Brain brain2(brain1);
	// Brain brain3;
	// brain3 = brain1;
	// }

	// PART C: ADDING IDEAS TO OUT PETS' BRAINS
	{
	std::cout << BOLD_UNDERLINE("\n3. TESTING THE ADDITION OF IDEAS TO OUT PETS' BRAIN 🧠\n") << std::endl;

	Dog *dog = new Dog();
	Cat *cat = new Cat();

	cat->hasNewIdea("Maybe I'll nap here all day.");
	cat->hasNewIdea("Hooman better not forget my evening treat, or there will be consequences");
	cat->hasNewIdea("Oh, what's that intriguing rustling sound? Time for a stealthy investigation.");

	dog->hasNewIdea("Is that the sound of the door? Must be hooman! Yay, playtime!");
	dog->hasNewIdea("Oh, the scent of fresh grass!");
	dog->hasNewIdea("Hmm, what's that noise? Better investigate and protect my territory!");
	
	std::cout << std::endl;
	cat->printAllIdeas();
	std::cout << std::endl;
	dog->printAllIdeas();
	std::cout << std::endl;

	delete cat;
	delete dog;
	}
	


	
	return 0;
}