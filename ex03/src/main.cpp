/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:03:53 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:55:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	IMateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	const AMateria *cure = new Cure();

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
	ICharacter *bob = new Character("bob");

	AMateria *curee = new Cure();
	AMateria *icee = new Ice();

	std::cout << std::endl;
	{
		Character udyr;
		udyr.equip(curee);
		udyr.equip(icee);
		udyr.equip(curee);
		udyr.equip(icee);
		udyr.showInventory();
	}
	// me->use(0, *bob);
	// me->use(1, *bob);
	std::cout << bob->getName() << " got " << bob->getHp() << " HP." <<std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}