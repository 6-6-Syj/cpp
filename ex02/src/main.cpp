/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:13:31 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:40:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void testFragConstruction()
{
	std::cout << "\n1. Default construction:" << std::endl;
	FragTrap fragDefault;

	std::cout << "\n2. Named construction:" << std::endl;
	FragTrap fragNamed("Fragy");

	std::cout << "\n3. Copy construction:" << std::endl;
	FragTrap fragCopied(fragNamed);

	std::cout << "\n4. Assignment operator:" << std::endl;
	FragTrap fragAssigned;
	fragAssigned = fragNamed;

	std::cout << "\n5. Destruction order verification:" << std::endl;
	{
		std::cout << "Creating FragTrap inside scope..." << std::endl;
		FragTrap scopedFrag("ScopedFrag");
		std::cout << "Leaving scope..." << std::endl;
	}

	std::cout << "\nFragTraps about to be destroyed:" << std::endl;
}

void testFragEdgeCases()
{
	std::cout << "\n1. Maximum damage test:" << std::endl;
	FragTrap toughFrag("Tough");
	toughFrag.takeDamage(99);
	toughFrag.attack("Enemy");
	toughFrag.highFivesGuys();
	toughFrag.takeDamage(1);

	std::cout << "\n2. Repair at max HP:" << std::endl;
	FragTrap healthyFrag("Healthy");
	healthyFrag.takeDamage(9);
	healthyFrag.beRepaired(3);
	healthyFrag.beRepaired(10000000);

	std::cout << "\n3. Mixed ClapTrap and FragTrap:" << std::endl;
	ClapTrap clap("Clapper");
	FragTrap frag("Frager");
	ScavTrap scav("Scaver");

	clap.attack("Target1");
	frag.attack("Target2");
	scav.attack("Target3");
}

int main()
{
	testFragConstruction();
	testFragEdgeCases();
	return 0;
}