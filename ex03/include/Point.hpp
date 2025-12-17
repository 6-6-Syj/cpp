/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:24:56 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/17 17:51:07 by jmagand          ###   ########.fr       */
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
	Point(const Fixed o1, const Fixed o2);
	Point(const Point &other);
	Point &operator=(const Point& other);
	~Point();
};