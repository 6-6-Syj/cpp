/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:05:46 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/21 23:01:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WRONG_CAT: Created" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WRONG_CAT: Constructor by type called" << std::endl;
	this->_type = type;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->_type = other._type;
	std::cout << "WRONG_CAT: Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WRONG_CAT: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WRONG_CAT: Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meooooow!" << std::endl;
}