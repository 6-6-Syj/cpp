/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:25 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:11:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

/* Default constructor */
Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const float val)
{
	this->_fixedPointValue = roundf(val * (1 << _fractionalBits));
}

/* Copy assignment operator */
Fixed &Fixed::operator=(Fixed &other)
{
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointValue = other._fixedPointValue;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (this->toFloat() * other.toFloat());
}