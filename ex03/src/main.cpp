/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:33 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:11:25 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.h"
#include <iostream>
#include <iomanip>

static void test_point(const std::string &name, const Point &a,
                       const Point &b, const Point &c, const Point &p)
{
    bool result = bsp(a, b, c, p);
    std::cout << name << ": ";
    std::cout << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main(void)
{
    Fixed ax(-3.55f), ay(4.22f);
    Point a(ax, ay);

    Fixed bx(-3.6f), by(-3.03f);
    Point b(bx, by);

    Fixed cx(3), cy(-3);
    Point c(cx, cy);

    test_point("Point A", a, b, c, a);

    Fixed mid_ab_x(-1.49f), mid_ab_y(1.95f);
    Point mid_ab(mid_ab_x, mid_ab_y);
    test_point("on edge AB", a, b, c, mid_ab);

    Fixed ix(-2.99f), iy(3.61f);
    Point i(ix, iy);
    test_point("inside", a, b, c, i);

    Fixed ox(0.26f), oy(0.27f);
    Point o(ox, oy);
    test_point("outside", a, b, c, o);

    return 0;
}