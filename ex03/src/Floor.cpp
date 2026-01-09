/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:08:57 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/09 16:07:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"
#include <iostream>

Floor *Floor::_floor = NULL;

Floor::Floor() : _capacity(MAX_MATERIA), _size(0)
{
	_ptrs = new AMateria *[_capacity];
	for (int i = 0; i < _capacity; i++)
		_ptrs[i] = NULL;
	_floor = NULL;
	std::cout << "Floor created" << std::endl;
}

Floor::~Floor()
{
	cleanFloor();
	if (_ptrs != NULL)
	{
		delete[] _ptrs;
		_ptrs = NULL;
	}
	std::cout << "Floor destroyed" << std::endl;
}

void Floor::resize(int newCapacity)
{
	AMateria **resized = new AMateria *[newCapacity];

	for (int i = 0; i < _size; i++)
		resized[i] = _ptrs[i];

	delete[] _ptrs;

	_ptrs = resized;
	_capacity = newCapacity;
}

Floor *Floor::getFloor()
{
	if (!_floor)
		_floor = new Floor;
	return _floor;
}

void Floor::dropMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "can't drop" << std::endl;
		return;
	}
	if (_size >= _capacity)
		resize(_capacity * 2);
	_ptrs[_size] = materia;
	_size++;
}

void Floor::displayFloor()
{
	std::cout << "Ground:" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		if (_ptrs[i])
			std::cout << "slot [" << i << "]: " << _ptrs[i]->getType() << std::endl;
		else
			std::cout << "slot [" << i << "]: NULL" << std::endl;
	}
}

void Floor::cleanFloor()
{
	for (int i = 0; i < _size; i++)
	{
		if (_ptrs[i] != NULL)
		{
			delete _ptrs[i];
			_ptrs[i] = NULL;
		}
	}
	_size = 0;
}

void Floor::destroyFloor()
{
	if (_floor != NULL)
	{
		delete _floor;
		_floor = NULL;
	}
}