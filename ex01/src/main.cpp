/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:13:31 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:32:25 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void testSection(const std::string &title)
{
	std::cout << "\n\033[1;36m" << title << "\033[0m" << std::endl;
}

void testScavConstruction()
{
	testSection("=== SCAVTRAP CONSTRUCTION TEST ===");

	std::cout << "\n1. Default construction:" << std::endl;
	ScavTrap scavDefault;

	std::cout << "\n2. Named construction:" << std::endl;
	ScavTrap scavNamed("Scavvy");

	std::cout << "\n3. Copy construction:" << std::endl;
	ScavTrap scavCopied(scavNamed);

	std::cout << "\n4. Assignment operator:" << std::endl;
	scavDefault = scavNamed;

	std::cout << "\n5. Destruction order verification:" << std::endl;
	{
		std::cout << "Creating ScavTrap inside scope..." << std::endl;
		ScavTrap scopedScav("ScopedScav");
		std::cout << "Leaving scope..." << std::endl;
	}

	std::cout << "\nScavTraps about to be destroyed:" << std::endl;
}

void testScavEdgeCases()
{
	testSection("=== SCAVTRAP EDGE CASES ===");

	std::cout << "1. Maximum damage test:" << std::endl;
	ScavTrap toughScav("Tough");
	toughScav.takeDamage(99);
	toughScav.attack("Enemy");
	toughScav.guardGate();
	toughScav.takeDamage(1);

	std::cout << "\n2. Repair at max HP:" << std::endl;
	ScavTrap healthyScav("Healthy");
	healthyScav.beRepaired(10);

	std::cout << "\n3. Mixed ClapTrap and ScavTrap:" << std::endl;
	ClapTrap clap("Clapper");
	ScavTrap scav("Scavver");

	clap.attack("Target1");
	scav.attack("Target2");
	scav.guardGate();
}

int main()
{
	testScavConstruction();
	testScavEdgeCases();
	return 0;
}