/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:58:58 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/16 00:14:02 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits;

public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed& other);
	~Fixed();
	int 	getRawBits() const;
	void 	setRawBits(int const raw);
	float 	toFloat() const;
	int 	toInt() const;
};

// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);