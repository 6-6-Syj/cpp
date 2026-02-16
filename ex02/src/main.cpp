/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:49:55 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/16 19:14:30 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

static void subject()
{
	std::cout << "=== Test 1: Subject ===" << std::endl;
	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		std::cout << "\nJ type: " << j->getType() << std::endl;
		std::cout << "I type: " << i->getType() << std::endl;

		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}
}

int main()
{
	subject();
	
	// AAnimal d;
	return 0;
}