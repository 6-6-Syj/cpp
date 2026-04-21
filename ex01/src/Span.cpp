/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:26:06 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/21 15:30:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <climits>

Span::Span() : _size(1)
{
	_arr.reserve(_size);
}

Span::Span(unsigned int size) : _size(size)
{
	_arr.reserve(_size);
}

Span::Span(const Span &copy) : _size(copy._size)
{
	_arr.reserve(_size);
	_arr.assign(copy._arr.begin(), copy._arr.end());
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr.reserve(_size);
		_arr.assign(other._arr.begin(), other._arr.end());
	}
	return *this;
}

Span::~Span() {}

std::vector<int> &Span::getVec()
{
	return _arr;
}

unsigned int &Span::getSize()
{
	return _size;
}

void Span::printVec()
{
	for (std::vector<int>::iterator it = _arr.begin(); it != _arr.end(); it++)
	{
		std::cout << *it;
		if (it != (_arr.end() - 1))
			std::cout << ", ";
	}
	std::cout << std::endl
			  << "(" << _arr.size() << "/" << _arr.capacity() << ")" << std::endl;
}

void Span::addNumber(int x)
{
	if (_arr.size() + 1 > _arr.capacity())
		throw(std::runtime_error("Can't add a new number."));
	else
		_arr.push_back(x);
}

void Span::addAllNumbers(std::vector<int> &toAdd)
{
	if (_arr.size() + toAdd.size() > _arr.capacity())
		throw(std::runtime_error("Can't add this range of number."));
	_arr.insert(_arr.begin(), toAdd.begin(), toAdd.end());
}

unsigned int Span::shortestSpan()
{
	if (_arr.size() < 2)
		throw(std::runtime_error("There's less than 2 values stored."));

	std::vector<int> &tmp(_arr);
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = UINT_MAX;
	std::vector<int>::iterator it = tmp.begin();
	
	for (std::vector<int>::iterator next = it + 1; next != tmp.end(); it++, next++)
	{
		unsigned int diff = static_cast<unsigned int>(*next) - static_cast<unsigned int>(*it);
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

unsigned int Span::longestSpan()
{
	if (_arr.size() < 2)
		throw(std::runtime_error("There's less than 2 values stored."));

	unsigned int min = INT_MAX;
	unsigned int max = INT_MIN;

	for (std::vector<int>::iterator it = _arr.begin(); it != _arr.end(); it++)
	{
		if (*it < static_cast<int>(min))
			min = *it;
		if (*it > static_cast<int>(max))
			max = *it;
	}

	return (max - min);
}