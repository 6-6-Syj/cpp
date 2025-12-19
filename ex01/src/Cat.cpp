/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:38:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 23:34:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "CAT: Default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "CAT: Constructor by type called" << std::endl;
	this->_type = type;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = other._type;
	std::cout << "CAT: Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
	std::cout << "CAT: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "CAT: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meooooow!" << std::endl;
}