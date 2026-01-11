/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:00 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 16:19:37 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits;

public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	/* Getters - Setters */
	int getRawBits() const;
	void setRawBits(const int raw);

	/* Comparison operators */
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/* Arithmetic operators */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;

	/* Increment and decrement operators */
	Fixed &operator++();	 // pre
	Fixed operator++(int x); // post
	Fixed &operator--();	 // pre
	Fixed operator--(int x); // post

	/* Utils */
	const static Fixed &min(const Fixed &other1, const Fixed &other2);
	const static Fixed &max(const Fixed &other1, const Fixed &other2);
	static Fixed &min(Fixed &other1, Fixed &other2);
	static Fixed &max(Fixed &other1, Fixed &other2);

	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);