/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:23:18 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:11:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int crossProduct(Point const a, Point const b, Point const p)
{
    Fixed res = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());

    if (res.toFloat() < 0)
        return -1;
    else if (res.toFloat() > 0)
        return 1;
    return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const int d1 = crossProduct(a, b, point);
    const int d2 = crossProduct(b, c, point);
    const int d3 = crossProduct(c, a, point);

    if (!d1 || !d2 || !d3)
        return true;
    if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
        return true;
    return false;
}