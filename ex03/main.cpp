/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:42:38 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/13 11:21:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

void testHumanA_subject()
{
    std::cout << "=== Test HumanA subject ===" << std::endl;
    Weapon club("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    std::cout << std::endl;
}

void testHumanB_subject()
{
    std::cout << "=== Test HumanB subject ===" << std::endl;
    Weapon club("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    std::cout << std::endl;
}

void testSameWeapon()
{
    std::cout << "=== Test same weapon ===" << std::endl;
    Weapon club("Knife");

    HumanA bob("Bob", club);
    HumanB jim("Jim");
    jim.setWeapon(club);

    bob.attack();
    jim.attack();
    club.setType("Katana");
    bob.attack();
    jim.attack();
    std::cout << std::endl;
}

void testHumanB_withoutWeapon()
{
    std::cout << "=== Test HumanB without weapon ===" << std::endl;
    HumanB joe("Joe");
    joe.attack();
    std::cout << std::endl;
}

void testHumanB_changeWeapon()
{
    std::cout << "=== Test HumanB change weapon ===" << std::endl;
    Weapon club("crude spiked club");
    Weapon sword("shiny sword");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    jim.setWeapon(sword);
    jim.attack();
    std::cout << std::endl;
}

HumanB *makeHumanB()
{
	Weapon club("crude spiked club");
	HumanB *jim = new HumanB("Jim");
	jim->setWeapon(club);
	jim->attack();
	return jim; // So club is destroyed here.
}

void testHumanB_crash()
{
    std::cout << "=== Test HumanB dangling weapon ===\n";
    HumanB *jim = makeHumanB();
    jim->attack(); // and there, pointing to random
    delete jim;
}

int main()
{
    testHumanA_subject();
    testHumanB_subject();
    testHumanB_withoutWeapon();
    testHumanB_changeWeapon();
    testSameWeapon();
	// testHumanB_crash();
    return 0;
}
