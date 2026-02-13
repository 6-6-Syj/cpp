/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:13:31 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:24:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#include <iostream>
#include "ClapTrap.hpp"

void testSection(const std::string &title)
{
	std::cout << "\n\033[1;36m" << title << "\033[0m" << std::endl;
}

void testConstruction()
{
	testSection("=== CONSTRUCTION TEST ===");

	ClapTrap defaultBot;
	ClapTrap namedBot("Bender");
	ClapTrap copiedBot(namedBot);
	defaultBot = namedBot;

	std::cout << std::endl;
}

void testAttack()
{
	testSection("=== ATTACK TEST ===");

	ClapTrap attacker("Attacker");

	std::cout << "Normal attacks:" << std::endl;
	attacker.attack("Target 1");
	attacker.setAd(6);
	attacker.attack("Target 2");
}

void testDamage()
{
	testSection("=== DAMAGE TEST ===");

	ClapTrap victim("Victim");

	std::cout << "Light damage:" << std::endl;
	victim.takeDamage(3);

	std::cout << "\nMedium damage:" << std::endl;
	victim.takeDamage(6);

	std::cout << "\nLethal damage:" << std::endl;
	victim.takeDamage(10);

	std::cout << "\nAttempt after death:" << std::endl;
	victim.takeDamage(1);
}

void testRepair()
{
	testSection("=== REPAIR TEST ===");

	ClapTrap patient("Patient");

	std::cout << "Normal repair:" << std::endl;
	patient.takeDamage(5);
	patient.beRepaired(3);

	std::cout << "\nFull repair:" << std::endl;
	patient.beRepaired(10);
}

void testEdgeCases()
{
	testSection("=== EDGE CASE TESTS ===");

	std::cout << "1. Action without hit points:" << std::endl;
	ClapTrap deadBot("DeadBot");
	deadBot.takeDamage(10);
	deadBot.attack("target");
	deadBot.beRepaired(5);

	std::cout << "\n2. Zero damage:" << std::endl;
	ClapTrap luckyBot("LuckyBot");
	luckyBot.takeDamage(0);
	luckyBot.attack("target");

	std::cout << "\n3. Maximum repair:" << std::endl;
	ClapTrap maxBot("MaxBot");
	maxBot.beRepaired(4294967295);
	maxBot.beRepaired(1000);
	maxBot.takeDamage(4294967295);
	maxBot.takeDamage(1000);
}

void testEnergyConsumption()
{
	testSection("=== ENERGY CONSUMPTION TEST ===");

	ClapTrap energetic("Energetic");

	std::cout << "10 actions to deplete energy:" << std::endl;
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "Action " << i << ": ";
		if (i % 2 == 0)
			energetic.attack("target");
		else
			energetic.beRepaired(1);
	}
}

int main()
{
	testConstruction();
	testAttack();
	testDamage();
	testRepair();
	testEnergyConsumption();
	testEdgeCases();
	return 0;
}