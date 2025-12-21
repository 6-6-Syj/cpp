/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:08:41 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/21 23:01:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "DOG: Created" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "DOG: Constructor by type called" << std::endl;
	this->_type = type;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_type = other._type;
	std::cout << "DOG: Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "DOG: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "DOG: Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "OOOF OOOF!" << std::endl;
}