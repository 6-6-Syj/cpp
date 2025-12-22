/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:59:41 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:30:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : _type("")
{
	// std::cout << "AMateria '" << _type << "' created. (default)" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	// std::cout << "AMateria '" << _type << "' created. (by type)" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	// std::cout << "AMateria '" << _type << "' created. (copy(AMat))" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "AMateria '" << _type << "' created (operator=)" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria '" << _type << "' destroyed." << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use(IChar &target) on target: " << target.getName() << std::endl;
}