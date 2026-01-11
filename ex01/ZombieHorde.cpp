/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:16:06 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *z = NULL;
	if (N < 1 || N > 100001)
	{
		std::cerr << "Please check the value" << std::endl;
		return z;
	}
	if (name.empty())
		name = "Nobody";
	z = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		z[i].setName(name);
		z[i].announce();
	}
	return z;
}
