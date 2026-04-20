/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:26:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 14:34:42 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(3) 
{
	_arr.reserve(_size);
}

Span::Span(unsigned int size) : _size(size)
{
	_arr.reserve(_size);
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = int();
}

Span::Span(const Span &copy) : _size(copy._size)
{
	_arr.reserve(_size);
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr.reserve(_size);
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

Span::~Span() {}

// int &Span::getValue(unsigned int &idx) const
// {
// 	for (std::vector::iterator)
// }

unsigned int &Span::getSize()
{
	return _size;
}

void Span::addNumber(int x)
{
	std::cout << _arr.capacity() << " " << _arr.size() << " " << x << std::endl;
	if (_arr.capacity() == 0)
		throw (std::runtime_error("Can't add a new number."));
	else
	{
		// _arr.insert(x);
		std::cout << "Faut placer " << x << std::endl;
	}
}

// void Span::addNumber(int x)
// {
// 	for (unsigned int i = 0; i < _size; i++)
// 	{
// 		if (_arr[i] == 0)
// 		{
// 			_arr[i] = x;
// 			return ;
// 		}
// 	}
// }

int Span::shortestSpan()
{
	int res = 0;
	return res ;
}

int Span::longestSpan()
{
	int min = __INT_MAX__;
	int max = -__INT_MAX__ -1;
	
	for (unsigned int i = 0; i < _size; i++)
    {
        if (_arr[i] < min)
			min = _arr[i];
		if (_arr[i] > max)
			max = _arr[i];
    }
	int res = max - min;
	
	return res ;
}

// std::ostream &operator<<(std::ostream &out, Span &sp)
// {

// 	return out;
// }