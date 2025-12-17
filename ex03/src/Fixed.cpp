/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:25 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/17 17:18:16 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed:: _fractionalBits = 8;

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int val)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = val;
}

Fixed::Fixed(const float val)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(val * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::Fixed(const Fixed& other)
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

bool Fixed::operator<(const Fixed& other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	
	res.setRawBits(this->_fixedPointValue + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->_fixedPointValue - other.getRawBits());
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->_fixedPointValue / other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->_fixedPointValue * other.getRawBits());
	return res;
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int x)
{
	Fixed	tmp = *this;
	
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
	Fixed	tmp = *this;
	
	(void)x;
	this->_fixedPointValue--;
	return tmp;
}

const Fixed& Fixed::min(const Fixed& other1, const Fixed& other2)
{
	if (other1.getRawBits() <= other2.getRawBits())
		return other1;
	return other2;
}

const Fixed& Fixed::max(const Fixed& other1, const Fixed& other2)
{
	if (other1.getRawBits() >= other2.getRawBits())
		return other1;
	return other2;
}

Fixed& Fixed::min(Fixed& other1, Fixed& other2)
{
	if (other1.getRawBits() <= other2.getRawBits())
		return other1;
	return other2;
}

Fixed& Fixed::max(Fixed& other1, Fixed& other2)
{
	if (other1.getRawBits() >= other2.getRawBits())
		return other1;
	return other2;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int	Fixed::toInt() const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}