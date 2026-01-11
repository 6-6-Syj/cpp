/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:42:38 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 15:06:22 by jmagand          ###   ########.fr       */
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

HumanA *makeHumanA()
{
    Weapon club("crude spiked club");
    HumanA *jim = new HumanA("Jim", club);
    jim->attack();
    return jim;
}

void testHumanA_crash()
{
    std::cout << "=== Test HumanA no weapon ===\n";
    HumanA *jim = makeHumanA();
    jim->attack();
    delete jim;
}

int main()
{
    testHumanA_subject();
    testHumanB_subject();
    testSameWeapon();
    testHumanB_withoutWeapon();
    testHumanB_changeWeapon();
    testSameWeapon();
    // testHumanA_crash(); // Problem there (Weapon scope makeHumanA)
    return 0;
}
