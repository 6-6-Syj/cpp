/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:24:56 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 16:26:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const Fixed &o1, const Fixed &o2);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	/* Getters */
	Fixed getX() const;
	Fixed getY() const;
};