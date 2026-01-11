/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:00:48 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:15:12 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	{
		Zombie z0;
		Zombie z2("Corinne");
		
		z0.announce();
		z2.announce();
		
		randomChump("Clovis");
	}
	
	{
		Zombie *z3 = newZombie("HEAP");
		z3->announce();
		delete z3;
	}
	
	{
		randomChump("STACK");
		// Zombie *z4 = newZombie("Leaks");
		// z4->announce();
	}

	return 0;
}