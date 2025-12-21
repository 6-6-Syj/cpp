/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:08:41 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:52:48 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal()
{
	std::cout << "DOG: Created" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "DOG: Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "DOG: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "DOG: Destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "OOOF OOOF!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}