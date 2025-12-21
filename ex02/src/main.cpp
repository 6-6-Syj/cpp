/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:49:55 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:55:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

static void subject()
{
	std::cout << "=== Test 1: Subject ===" << std::endl;
	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		std::cout << "\nJ type: " << j->getType() << std::endl;
		std::cout << "I type: " << i->getType() << std::endl;

		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}

	std::cout << "\n\n=== Test 2: Array of AAnimals (50% Dog, 50% Cat) ===" << std::endl;
	{
		const int arraySize = 100;

		AAnimal *Aanimals[arraySize];

		for (int i = 0; i < arraySize / 2; i++)
			Aanimals[i] = new Dog();
			
		for (int i = arraySize / 2; i < arraySize; i++)
			Aanimals[i] = new Cat();

		std::cout << "\nMaking sounds from array:" << std::endl;
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "AAnimal " << i << " (" << Aanimals[i]->getType() << "): ";
			Aanimals[i]->makeSound();
		}

		std::cout << "\nDeleting all Aanimals:" << std::endl;
		for (int i = 0; i < arraySize; i++)
			delete Aanimals[i];
	}
}

static void deepCopy()
{
	std::cout << "\n\n=== Test 3: Deep copy verification ===" << std::endl;
	{
		std::cout << "\n--- Testing Dog deep copy ---" << std::endl;
		Dog *originalDog = new Dog();
		Dog *copiedDog = new Dog(*originalDog);

		originalDog->getBrain()->setIdea(0, "Original Dog's First Idea");
		originalDog->getBrain()->setIdea(1, "Original Dog's Second Idea");

		copiedDog->getBrain()->setIdea(0, "Copied Dog's First Idea");
		copiedDog->getBrain()->setIdea(1, "Copied Dog's Second Idea");

		std::cout << "\nOriginal Dog ideas:" << std::endl;
		std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

		std::cout << "\nCopied Dog ideas:" << std::endl;
		std::cout << "Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;

		Dog assignedDog;
		Dog &assignedDogRef = assignedDog;
		(void)assignedDogRef;
		
		assignedDog = *originalDog;
		assignedDog.getBrain()->setIdea(0, "Assigned Dog's Modified Idea");

		std::cout << "\nAfter modifying assigned dog:" << std::endl;
		std::cout << "Original Dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Assigned Dog idea 0: " << assignedDog.getBrain()->getIdea(0) << std::endl;

		delete originalDog;
		delete copiedDog;
	}

	{
		std::cout << "\n--- Testing Cat deep copy ---" << std::endl;
		Cat *originalCat = new Cat();
		Cat *copiedCat = new Cat(*originalCat);

		originalCat->getBrain()->setIdea(0, "Original Cat's Mouse Chase Idea");
		copiedCat->getBrain()->setIdea(0, "Copied Cat's Nap Idea");

		std::cout << "\nOriginal Cat idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Cat idea 0: " << copiedCat->getBrain()->getIdea(0) << std::endl;

		delete originalCat;
		delete copiedCat;
	}
}

static void brainTest()
{
	std::cout << "\n\n=== Test 4: Brain functionality ===" << std::endl;
	{
		Brain brain;

		for (int i = 0; i < 5; i++)
		{
			std::ostringstream oss;
			oss << "Idea number " << i;
			brain.setIdea(i, oss.str());
		}

		for (int i = 0; i < 5; i++)
			std::cout << "Idea " << i << ": " << brain.getIdea(i) << std::endl;

		std::cout << "Idea 154 (invalid): " << brain.getIdea(154) << std::endl;
		std::cout << "Idea -1 (invalid): " << brain.getIdea(-1) << std::endl;
	}
}

static void polyMorph()
{
	std::cout << "\n\n=== Test 5: Polymorphism verification ===" << std::endl;
	{
		AAnimal *polyArray[4];

		polyArray[0] = new Dog();
		polyArray[1] = new Cat();
		polyArray[2] = new Dog();
		polyArray[3] = new Cat();

		std::cout << "\nPolymorphic behavior:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "AAnimal " << i << " type: " << polyArray[i]->getType();
			std::cout << " - Sound: ";
			polyArray[i]->makeSound();
		}

		std::cout << "\nCleaning up polymorphic array:" << std::endl;
		for (int i = 0; i < 4; i++)
			delete polyArray[i];
	}
}

int main()
{
	subject();
	deepCopy();
	brainTest();
	polyMorph();

	AAnimal a;
	(void)a;
	
	// AAnimal* ptr = new AAnimal();
	// (void)ptr;
	
	return 0;
}