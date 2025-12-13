/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:06 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/13 15:35:14 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *ptr = NULL;
	if (N < 1 || N > 100001)
	{
		std::cerr << "Please check the value" << std::endl;
		return ptr;
	}
	if (name.empty())
		name = "Nobody";
	ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ptr[i].setName(name);
		ptr[i].announce();
	}
	return ptr;
}
