/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:26:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 11:04:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size)
{
	_arr = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = int();
}

Span::Span(const Span &copy) : _size(copy._size)
{
	delete []_arr;
	_arr = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		delete []_arr;
		_size = other._size;
		_arr = new int[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

Span::~Span() 
{
	delete []_arr;
}

Span &Span::operator[](unsigned int x)
{
	return _arr[x];
}

void Span::addNumber(int x)
{
	tmp = new int[_size + 1];
	
	unsigned int i = 0;
	for (i; i < _size; i++)
		tmp[i] = _arr[i];
	tmp[i] = x;

	delete []_arr;
	
	_size = _size + 1;
	_arr = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = tmp[i];

	delete []tmp;
}