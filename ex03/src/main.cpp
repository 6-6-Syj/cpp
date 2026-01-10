/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:03:53 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/10 12:06:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Floor.hpp"
#include "Cure.hpp"
#include <iostream>

void test_constructors()
{
	std::cout << "=== CONSTRUCTORS TEST ===" << std::endl;

	AMateria *cure = new Cure();

	std::cout << std::endl;
	{
		Ice ice2;
		delete ice2.clone();
	}
	std::cout << std::endl;
	{
		Cure cure1;
		Cure cure2;
		cure2 = cure1;
	}
	std::cout << std::endl;

	delete cure;
	std::cout << std::endl;
}

void test_inventory()
{
	std::cout << std::endl
			  << "====== INVENTORY TEST ======" << std::endl;
	
	{
		Floor *floor = Floor::getFloor();
		Character john;

		std::cout << "====== BAD MATERIA ======" << std::endl;
		AMateria *iceeeee = NULL;
		john.equip(iceeeee);

		std::cout << std::endl << "====== 1 ======" << std::endl;
		john.equip(new Cure());
		john.showInventory();
		john.unequip(0);
		
		john.equip(new Ice());
		john.equip(new Cure());
		john.unequip(0);
		john.equip(new Cure());
		john.equip(new Ice());
		john.equip(new Ice());
		john.showInventory();

		std::cout << std::endl << "====== FULL BAG ======" << std::endl;
		john.equip(new Ice());
		john.unequip(3);
		john.unequip(1);
		john.showInventory();
		
		john.unequip(3);
		john.unequip(15);
		john.equip(new Cure());
		john.equip(new Ice());
		john.showInventory();
		john.unequip(0);
		
		std::cout << "Floor contents:" << std::endl;
		floor->displayFloor();
		
		std::cout << std::endl << "====== CLEANUP ======" << std::endl;
		for (int i = 0; i < 4; i++) 
			john.unequip(i);
		john.showInventory();
		
		floor->cleanFloor();
		floor->displayFloor();
		
		std::cout << "============================" << std::endl << std::endl;
	}
}

void test_comprehensive_materia()
{
	std::cout << "\n=== COMPREHENSIVE MATERIA TEST ===\n";

	{
		std::cout << "\n--- Test 1: Deep Copy and Clone ---\n";
		Ice *ice1 = new Ice();
		Ice *ice2 = dynamic_cast<Ice *>(ice1->clone());

		std::cout << "ice1 address: " << ice1 << std::endl;
		std::cout << "ice2 (clone) address: " << ice2 << std::endl;
		std::cout << "Are they different objects? " << (ice1 != ice2 ? "YES" : "NO") << std::endl;

		delete ice1;
		delete ice2;
	}

	{
		std::cout << "\n--- Test 2: Unknown Materia Types ---\n";
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		AMateria *unknown = src.createMateria("fire");
		if (unknown == NULL)
			std::cout << "Correctly returned NULL for unknown type 'fire'\n";
		else
			std::cout << "ERROR: Should return NULL for unknown type\n";

		AMateria *ice = src.createMateria("ice");
		if (ice != NULL)
			std::cout << "Successfully created ice materia\n";
		delete ice;
	}

	{
		std::cout << "\n--- Test 3: Full Inventory Management ---\n";
		Character alice("Alice");

		for (int i = 0; i < 4; i++)
		{
			alice.equip(new Cure());
		}

		alice.equip(new Ice());

		for (int i = 0; i < 4; i++)
		{
			alice.unequip(i);
		}

		alice.equip(new Ice());
		alice.equip(new Cure());
		alice.equip(new Ice());

		std::cout << "Inventory after mixed fill:\n";
		alice.showInventory();
	}

	{
		std::cout << "\n--- Test 4: Materia Usage ---\n";
		Character bob("Bob");
		Character enemy("Goblin");

		bob.equip(new Ice());
		bob.equip(new Cure());
		bob.equip(new Ice());

		std::cout << "Using all equipped materias:\n";
		for (int i = 0; i < 4; i++)
		{
			bob.use(i, enemy);
		}

		bob.use(3, enemy);
	}

	{
		std::cout << "\n--- Test 5: Character Copy with Inventory ---\n";
		Character original("Original");
		original.equip(new Ice());
		original.equip(new Cure());

		Character copy(original);
		Character assigned("Temp");
		assigned = original;

		std::cout << "Original inventory: ";
		original.showInventory();
		std::cout << "Copy inventory: ";
		copy.showInventory();
		std::cout << "Assigned inventory: ";
		assigned.showInventory();

		std::cout << "\nUnequipping from original (should not affect copies):\n";
		original.unequip(0);
		std::cout << "Original after unequip: ";
		original.showInventory();
		std::cout << "Copy after original unequip: ";
		copy.showInventory();
		
		Floor::getFloor()->cleanFloor();
	}

	{
		std::cout << "\n--- Test 6: Floor Management ---\n";
		Floor* floor = Floor::getFloor();
		Character charlie("Charlie");

		for (int i = 0; i < 6; i++)
		{
			if (i % 2 == 0)
				charlie.equip(new Ice());
			else
				charlie.equip(new Cure());

			if (i > 1)
			{
				charlie.unequip(i - 2);
			}
		}

		std::cout << "Floor content after unequips:\n";
		floor->displayFloor();

		floor->cleanFloor();
		std::cout << "Floor after cleanup:\n";
		floor->displayFloor();
	}

	{
		std::cout << "\n--- Test 7: Complex Scenario ---\n";
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *hero = new Character("Hero");
		ICharacter *monster = new Character("Monster");

		AMateria *m1 = src->createMateria("ice");
		AMateria *m2 = src->createMateria("cure");
		AMateria *m3 = src->createMateria("ice");
		AMateria *m4 = src->createMateria("cure");

		hero->equip(m1);
		hero->equip(m2);
		hero->equip(m3);

		hero->unequip(1);
		hero->equip(m4);

		std::cout << "Hero attacks monster:\n";
		for (int i = 0; i < 4; i++)
			hero->use(i, *monster);

		monster->equip(src->createMateria("cure"));

		delete monster;
		delete hero;
		delete src;
	}
}

void test_edge_cases()
{
	std::cout << "\n=== EDGE CASES TEST ===\n";

	{
		std::cout << "\n--- Test 1: NULL Pointers ---\n";
		Character test("Test");

		test.equip(NULL);

		Character target("Target");
		test.use(-1, target);
		test.use(10, target);

		test.unequip(-1);
		test.unequip(10);
	}

	{
		std::cout << "\n--- Test 2: Multiple createMateria calls ---\n";
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria *m1 = src.createMateria("ice");
		AMateria *m2 = src.createMateria("ice");
		AMateria *m3 = src.createMateria("ice");

		std::cout << "Created 3 ice materias at addresses: "
				  << m1 << ", " << m2 << ", " << m3 << std::endl;

		delete m1;
		delete m2;
		delete m3;
	}

	{
		std::cout << "\n--- Test 3: Type Case Sensitivity ---\n";
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria *m1 = src.createMateria("Ice");
		AMateria *m2 = src.createMateria("ICE");
		AMateria *m3 = src.createMateria("ice");

		if (m1)
			std::cout << "Created materia with 'Ice'\n";
		if (m2)
			std::cout << "Created materia with 'ICE'\n";
		if (m3)
			std::cout << "Created materia with 'ice'\n";

		delete m1;
		delete m2;
		delete m3;
	}
}

void subject()
{
	std::cout << "\n=== ORIGINAL SUBJECT TEST ===\n";

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	test_constructors();
	test_inventory();
	test_comprehensive_materia();
	test_edge_cases();

	subject();

	std::cout << "\n=== ALL TESTS COMPLETED ===\n";
	Floor::destroyFloor();

	return 0;
}