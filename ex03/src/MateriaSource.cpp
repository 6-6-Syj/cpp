/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:17:29 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 23:57:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : known()
{
	std::cout << "MateriaSource created! (default)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->known[i] = other.known[i];
	std::cout << "MateriaSource copied! (copy(MateriaSource))" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
			this->known[i] = other.known[i];
	}
	std::cout << "MateriaSource copied! (operator=)" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria *ptr)
{
	std::cout << "Learning...." << std::endl;
	(void)ptr;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	std::cout << "Woah! It creates Materia!" << std::endl;
	// create a new Materia -> if (ice) then new Ice;
	// return 0 if parameter is unknown type;
	(void)type;
	return NULL;
}