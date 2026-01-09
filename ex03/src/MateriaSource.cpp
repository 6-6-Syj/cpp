/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:17:29 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 14:22:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _known()
{
	// std::cout << "MateriaSource created! (default)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_known[i] = other._known[i];
	// std::cout << "MateriaSource copied! (copy(MateriaSource))" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
			this->_known[i] = other._known[i];
	}
	// std::cout << "MateriaSource copied! (operator=)" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_known[i])
			delete _known[i];
	}
	// std::cout << "MateriaSource destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria *ptr)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (!_known[i])
		{
			_known[i] = ptr;
			std::cout << ptr->getType() << " has been learned" << std::endl;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_known[i] && _known[i]->getType() == type)
			return _known[i]->clone();
	}
	std::cout << "This materia hasn't been learned" << std::endl;
	return NULL;
}