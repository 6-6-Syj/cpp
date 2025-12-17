/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/17 17:49:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(const Fixed o1, const Fixed o2)
{
	this->_x = o1;
	this->_y = o2;
}

Point::Point(const Point& other)
{
	this->_x = other._x; 
	this->_y = other._y; 
}

Point &Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}

Point::~Point() {}