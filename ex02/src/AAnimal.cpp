/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:54:54 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:51:06 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("unknown")
{
	std::cout << "AANIMAL: Created" << std::endl;
};

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "AANIMAL: Copy constructor called" << std::endl;
};

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AANIMAL: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AANIMAL: Destroyed" << std::endl;
};

void AAnimal::makeSound() const
{
	std::cout << "Krkrkrrrr krrr krkrkrkr!" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}