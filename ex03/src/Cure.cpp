/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:05:37 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 13:51:48 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria()
{
	_type = "cure";
	// std::cout << "Cure AMateria '" << _type << "' created. (default)" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria()
{
	this->_type = other._type;
	// std::cout << "Cure AMateria '" << _type << "' created. (copy(Cure))" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	// std::cout << "Cure AMateria '" << _type << "' created. (operator=)" << std::endl;
	return *this;
}

Cure::~Cure()
{
	// std::cout << "Cure AMateria '" << _type << "' destroyed." << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *Cure::clone() const 
{
	std::cout << "cloning Cure..." << std::endl;
	return new Cure(*this);
}