/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:40:48 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/23 00:53:19 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

const int Character::MAX_HP = 100;

Character::Character() : _name("Nobody"), _hp(MAX_HP)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->inventory[i] = NULL;
	std::cout << this->_name << " created ! (default)" << std::endl;
}

Character::Character(const std::string name) : _name(name), _hp(MAX_HP)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->inventory[i] = NULL;
	std::cout << this->_name << " created ! (by name)" << std::endl;
}

Character::Character(const Character &other)
{
	std::string tmp = this->_name;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_materiaCount = other._materiaCount;
	for (int i = 0; i < _materiaCount; i++)
		this->inventory[i] = other.inventory[i];
	std::cout << "From " << tmp << " to " << _name << std::endl
			  << "(copy(Char))" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		std::string tmp = this->_name;
		this->_name = other._name;
		this->_hp = other._hp;
		this->_materiaCount = other._materiaCount;
		for (int i = 0; i < _materiaCount; i++)
			this->inventory[i] = other.inventory[i];
		std::cout << "From " << tmp << " to " << _name << std::endl
				  << "Need to do deep copy of char's bag." << std::endl
				  << "(operator=)" << std::endl;
	}
	return (*this);
}

Character::~Character()
{
	// for (int i = 0; i < _materiaCount; i++)
	// {
	// 	if (_inventory[i])
	// 	delete this->inventory[i];
	// }
	std::cout << "Char " << this->_name << " died. "
			  << "-> Need to delete materias!" << std::endl;
}

std::string const &Character::getName() const
{
	return this->_name;
}

int Character::getHp() const
{
	return this->_hp;
}

void Character::equip(AMateria *m)
{
	if (!m || this->_materiaCount >= MAX_MATERIA)
		return ;
		
	int i = 0;
    while (i < MAX_MATERIA)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            this->_materiaCount++;
            return;
        }
        i++;
    }
	std::cout << "Char should equip: " << m << std::endl
			  << "materia equipped: " << _materiaCount << std::endl;
}

void Character::unequip(int idx)
{
	this->_materiaCount -= 1;
	std::cout << "Char unequip slot[" << idx << "]" << std::endl
			  << "materia equipped: " << _materiaCount << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _materiaCount && inventory[idx] != NULL)
		inventory[idx]->use(target);
	std::cout << "Char use slot[" << idx << "] on char: " << target.getName() << std::endl;
}

void Character::showInventory() const
{
	std::cout << this->_name << "'s inventory:" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->inventory[i])
			std::cout << "[" << i << "] = " << this->inventory[i]->getType() << std::endl;
	}
	std::cout << std::endl;
}