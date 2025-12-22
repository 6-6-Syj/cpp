/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:05:59 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:16:28 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria()
{
	_type = "ice";
	std::cout << "Ice AMateria '" << _type << "' created. (default)" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->_type = other._type;
	std::cout << "Ice AMateria '" << _type << "' created. (copy(Ice))" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Ice AMateria '" << _type << "' created. (operator=)" << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice AMateria '" << _type << "' destroyed." << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *Ice::clone() const 
{
	std::cout << "cloning Ice..." << std::endl;
	return new Ice(*this);
}