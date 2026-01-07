/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:08:57 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/07 16:11:27 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"
#include <iostream>

Floor::Floor() : _capacity(10), _size(0)
{
	_ptrs = new AMateria*[_capacity];
	for (int i = 0; i < _capacity; i++)
		_ptrs[i] = NULL;
	std::cout << "Floor created" << std::endl;
}

Floor::Floor(const Floor &other)
{
	_capacity = other._capacity;
	_size = other._size;
	_ptrs = new AMateria*[_capacity];

	for (int i = 0; i < _size; i++)
		_ptrs[i] = other._ptrs[i];
}

Floor &Floor::operator=(const Floor &other)
{
	if (this != &other)
	{
		for (int i = 0; i < other._size; i++)
			delete _ptrs[i];
		delete[] _ptrs;

		_capacity = other._capacity;
		_size = other._size;
		_ptrs = new AMateria*[_capacity];

		for (int i = 0; i < _size; i++)
			_ptrs[i] = other._ptrs[i];
	}
	return *this;
}

Floor::~Floor()
{
	for (int i = 0; i < _size; i++)
		delete _ptrs[i];
	delete[] _ptrs;
	std::cout << "Floor destroyed" << std::endl;
}

void Floor::resize(int newCapacity)
{
	AMateria **resized = new AMateria*[newCapacity];

	for (int i = 0; i < _size; i++)
		resized[i] = _ptrs[i];

	delete[] _ptrs;

	_ptrs = resized;
	_capacity = newCapacity;
}

void Floor::pushBack(AMateria *materia)
{
	if (materia)
	{
		if (_size >= _capacity)
			resize(_capacity * 2);
		_ptrs[_size] = materia;
		_size++;
		return;
	}
}