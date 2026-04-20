/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:26:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 10:10:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) : _size(size)
{
	_arr = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_arr[i] = 0;
	}
}

Span::Span(const Span &copy)
{
	if ()
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		delete _arr[];
		_size = other._size;
		_arr = new int[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

Span::~Span() {}