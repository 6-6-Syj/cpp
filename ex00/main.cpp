/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:00:48 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 15:12:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie z1;
	Zombie z2("Jean-Eude");
	Zombie* z3;
	
	z3 = newZombie("Jeremiade");
	z1.announce();
	z3->announce();
	z2.announce();
	randomChump("Clovis");
	delete z3;
}