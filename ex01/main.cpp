/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:15:47 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 15:02:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z;

	// z = zombieHorde(3, "John");
	// if (z)
	// 	delete[] z;

	// z = zombieHorde(-102, "< 0");

	// z = zombieHorde(100000, "Ju");
	// if (z)
	// 	delete[] z;

	z = zombieHorde(5, "");
	if (z)
		delete[] z;

	// z = zombieHorde(200000000, "< 0");
	return 0;
}
