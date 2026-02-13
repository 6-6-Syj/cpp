/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:25 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 13:37:15 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _fixedPointValue(val << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _fixedPointValue(roundf(val * (1 << _fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other._fixedPointValue);
	return *this;
}

Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointValue = other._fixedPointValue;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member fuction called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->_fixedPointValue + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->_fixedPointValue - other.getRawBits());
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	long long tmp = (static_cast<long long>(_fixedPointValue) << _fractionalBits);
	res.setRawBits(static_cast<int>(tmp / other._fixedPointValue));
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	long long tmp = static_cast<long long>(_fixedPointValue) *
					 static_cast<long long>(other._fixedPointValue);
	res.setRawBits(static_cast<int>(tmp >> _fractionalBits));
	return res;
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int x)
{
	Fixed tmp = *this;

	(void)x;
	this->_fixedPointValue++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int x)
{
	Fixed tmp = *this;

	(void)x;
	this->_fixedPointValue--;
	return tmp;
}

const Fixed &Fixed::min(const Fixed &other1, const Fixed &other2)
{
	if (other1.getRawBits() <= other2.getRawBits())
		return other1;
	return other2;
}

const Fixed &Fixed::max(const Fixed &other1, const Fixed &other2)
{
	if (other1.getRawBits() >= other2.getRawBits())
		return other1;
	return other2;
}

Fixed &Fixed::min(Fixed &other1, Fixed &other2)
{
	if (other1.getRawBits() <= other2.getRawBits())
		return other1;
	return other2;
}

Fixed &Fixed::max(Fixed &other1, Fixed &other2)
{
	if (other1.getRawBits() >= other2.getRawBits())
		return other1;
	return other2;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}