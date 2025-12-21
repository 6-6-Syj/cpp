/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:38:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:32:58 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "CAT: Created" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "CAT: Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "CAT: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "CAT: Destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meooooow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}