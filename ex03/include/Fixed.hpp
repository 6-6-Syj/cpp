/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:00 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 16:26:23 by jmagand          ###   ########.fr       */
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
	Fixed(const float val);
	Fixed(const Fixed &other);
	Fixed &operator=(Fixed &other);
	~Fixed();

	/* Getters - Setters */
	int getRawBits() const;
	void setRawBits(const int raw);

	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	float toFloat() const;
};