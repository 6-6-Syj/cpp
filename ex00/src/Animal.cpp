/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:54:54 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 23:36:33 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("unknown")
{
	std::cout << "ANIMAL: Default constructor called" << std::endl;
};

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "ANIMAL: Constructor by type called" << std::endl;
};

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "ANIMAL: Copy constructor called" << std::endl;
};

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "ANIMAL: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "ANIMAL: Destructor called" << std::endl;
};

void Animal::makeSound() const
{
	std::cout << "Krkrkrrrr krrr krkrkrkr!" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}