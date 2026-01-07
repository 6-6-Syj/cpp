/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:03:53 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/07 16:19:15 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Floor.hpp"
#include "Cure.hpp"
#include <iostream>

void test_inventory() 
{
	AMateria *curee = new Cure();
	AMateria *icee = new Ice();

	std::cout << std::endl;
	{
		AMateria *iceeeee = NULL;
		Character john;
		
		john.showInventory();
		john.equip(curee);
		john.equip(iceeeee);
		john.equip(curee);
		john.equip(icee);
		john.equip(curee);
		john.showInventory();

		john.unequip(2);
		john.showInventory();

		john.unequip(3);
		john.unequip(3);
		john.unequip(15);
		john.equip(icee);
		john.equip(icee);
		john.showInventory();
	}
}

int main()
{
	IMateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
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

	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// test_inventory();
	std::cout << std::endl;
	
	ICharacter *bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);
	std::cout << bob->getName() << " got " << bob->getHp() << " HP." <<std::endl;
	delete bob;
	
	delete me;
	delete src;
	
	return 0;
}