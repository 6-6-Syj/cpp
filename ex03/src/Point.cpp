/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:04 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/21 14:56:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const Fixed &o1, const Fixed &o2) : _x(o1), _y(o2) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }