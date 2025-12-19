/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 13:01:40 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const Fixed &o1, const Fixed &o2) : _x(o1), _y(o2) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }