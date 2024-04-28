/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:30:39 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/28 21:41:35 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	// PART A: SUBTYPE POLYMORPHISM OF THE makeSound()
	{
	std::cout << BOLD_UNDERLINE("\nTEST 1: SUBTYPE POLYMORPHISM\n") << std::endl;
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// const AAnimal* a = new AAnimal();
	// AAnimal test;  --> not possible since AAnimal is an abstract class
	
	
	
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
	}

	// // PART B: THE REQUEST FORM THE SUBJECT WHILE LOOP
	// {
	// std::cout << BOLD_UNDERLINE("\nTEST 2: THE REQUESTED FROM THE SUBJECT WHILE LOOP:\n") << std::endl;

	// AAnimal* AAnimals[8];

	// std::cout << UNDERLINE("a) Half of the objects are constructed as Dogs:") << std::endl;
	// for (int i = 0; i < 4; i++) {
	// 	AAnimals[i] = new Dog();
	// }
	// std::cout << UNDERLINE("\nb) And the rest half are constructed as Cats:") << std::endl;
	// for (int i = 4; i < 8; i++) {
	// 	AAnimals[i] = new Cat();
	// }
	// std::cout << UNDERLINE("\nDestruction of all, directly, as AAnimals:") << std::endl;
	// for (int i = 0; i < 8; i++) {
	// 	delete AAnimals[i];
	// }
	// }

	// // PART C: ADDING IDEAS TO OUT PETS' BRAINS
	// {
	// std::cout << BOLD_UNDERLINE("\n3. TESTING THE ADDITION OF IDEAS TO OUT PETS' BRAIN 🧠\n") << std::endl;

	// Dog *dog = new Dog();
	// Cat *cat = new Cat();

	// cat->hasNewIdea("Maybe I'll nap here all day.");
	// cat->hasNewIdea("Hooman better not forget my evening treat, or there will be consequences!");
	// cat->hasNewIdea("Oh, what's that intriguing rustling sound? Time for a stealthy investigation.");

	// dog->hasNewIdea("Is that the sound of the door? Must be hooman! Yay, playtime!");
	// dog->hasNewIdea("Oh, the scent of fresh grass!");
	// dog->hasNewIdea("Hmm, what's that noise? Better investigate and protect my territory!");
	
	// std::cout << std::endl;
	// cat->printAllIdeas();
	// std::cout << std::endl;
	// dog->printAllIdeas();
	// std::cout << std::endl;

	// delete cat;
	// delete dog;
	// }

	// // PART D: TESTING THE CREATION OF DEEP COPIES
	// std::cout << BOLD_UNDERLINE("\n4. TESTING THE CREATION OF DEEP COPIES 🧠\n") << std::endl;
	// {
	// Dog *first_dog = new Dog();
	// first_dog->hasNewIdea("Sleeping time!");
	// std::cout << "Ideas of first Dog: " << std::endl;
	// first_dog->printAllIdeas();

	// std::cout << "Creation of a Copy Dog from First Dog" << std::endl;
	// Dog *copy_dog = new Dog(*first_dog); // Copy constructor call for creation of a deep copy
	// std::cout << "Copy Dog's ideas initially, after the copy: " << std::endl;
	// copy_dog->printAllIdeas();
	
	// std::cout << "copy_dog has a new idea " << std::endl;
	// copy_dog->hasNewIdea("Time for walk!");
	// std::cout << "Copied Dog's Brain after the addition of the Idea: " << std::endl;
	// copy_dog->printAllIdeas();
	
	// std::cout << "First Dog's Brain stay the same: " << std::endl;
	// first_dog->printAllIdeas(); //if it was a shallow copy, first dog's brain would have also been modified from the addition of the idea.
	
	// delete first_dog;
	// delete copy_dog;
	// }
	
	// Dog dog;
	// AAnimal animal = AAnimal();
	
	return 0;
}