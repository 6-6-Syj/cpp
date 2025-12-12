/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:06 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 16:47:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		return (NULL);
	}
	Zombie* ptr = new Zombie[N];
	for (int i = 0; i < N; i++) {
		ptr[i].setName(name);
		ptr[i].announce();
	}
	return (ptr);
}