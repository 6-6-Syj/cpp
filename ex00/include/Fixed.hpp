/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:58:58 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/16 00:02:58 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int _value;
	static const int _fractionalBits;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
};