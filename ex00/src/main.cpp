/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:49:55 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/21 22:32:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrong = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl << std::endl;
	
	{
		Dog didier;
		std::cout << didier.getType() << " " << std::endl;
		Dog rob(didier);
	
		didier = rob;
	}

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	wrong->makeSound();
	std::cout << std::endl;
	
	delete dog;
	delete cat;
	delete meta;
	delete wrong;
	return 0;
}