/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:40:48 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/10 12:02:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Floor.hpp"
#include <iostream>

Character::Character() : _name("Nobody"), _materiaCount(0)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " created ! (default)" << std::endl;
}

Character::Character(const std::string name) : _name(name), _materiaCount(0)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " created ! (by name)" << std::endl;
}

Character::Character(const Character &other) : _name(other._name + "_copy"), _materiaCount(0)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
			_materiaCount++;
		}
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
	}
	_materiaCount = 0;
	_name = other._name;

	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
			_materiaCount++;
		}
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
		{
			delete this->_inventory[i];
			_inventory[i] = NULL;
		}
	}
	std::cout << this->_name << " died. " << std::endl;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Problem with materia pointed" << std::endl;
		return;
	}

	if (this->_materiaCount >= MAX_MATERIA)
	{
		std::cout << "Inventory is full, deleting " << m->getType() << std::endl;
		delete m;
		return;
	}

	int i = 0;
	while (i < MAX_MATERIA)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << m->getType() << " equipped on slot [" << i << "]" << std::endl;
			this->_materiaCount++;
			return;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if ((idx < 0 || idx >= MAX_MATERIA) || !_inventory[idx])
	{
		std::cout << "unequip: Nothing happened" << std::endl;
		return;
	}
	
    std::cout << _inventory[idx]->getType() << " unequipped on inventory[" << idx << "]" << std::endl;
    
    Floor* floor = Floor::getFloor();
    floor->dropMateria(_inventory[idx]);
    _inventory[idx] = NULL;
    _materiaCount--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _materiaCount && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << "use: Something goes wrong" << std::endl;
}

void Character::showInventory() const
{
	std::cout << this->_name << "'s inventory:" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i])
			std::cout << "[" << i << "] = " << this->_inventory[i]->getType() << std::endl;
		else
			std::cout << "[" << i << "] = NULL" << std::endl;
	}
	std::cout << std::endl;
}

bool Character::isSlotOccupied(int idx) const
{
	if (idx < 0 || idx >= 4)
		return false;
	return _inventory[idx] != NULL;
}