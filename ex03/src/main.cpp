/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:33 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/18 14:56:52 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.h"
#include <iostream>
#include <iomanip>

static void test_point(const std::string& name, const Point& a, 
                const Point& b, const Point& c, const Point& p) {
    bool result = bsp(a, b, c, p);
    std::cout << std::setw(20) << name << ": ";
    std::cout << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main(void)
{
    Fixed ax(-3.41f), ay(3.3f);
    Point a(ax, ay);
    
    Fixed bx(-3.77f), by(-2.7f);
    Point b(bx, by);

    Fixed cx(2.51f), cy(-2.6f);
    Point c(cx, cy);
    
    std::cout << "=== verticles tests (^) ===" << std::endl;
    test_point("Point A (verticle)", a, b, c, a);
    test_point("Point B (verticle)", a, b, c, b);
    test_point("Point C (verticle)", a, b, c, c);

    std::cout << "\n=== edge test (|)===" << std::endl;
    Fixed mid_ab_x = Fixed((ax.toFloat() + bx.toFloat()) / 2.0f);
    Fixed mid_ab_y = Fixed((ay.toFloat() + by.toFloat()) / 2.0f);
    Point mid_ab(mid_ab_x, mid_ab_y);
    test_point("on edge AB", mid_ab, a, b, c);
    
    Fixed mid_bc_x = Fixed((bx.toFloat() + cx.toFloat()) / 2.0f);
    Fixed mid_bc_y = Fixed((by.toFloat() + cy.toFloat()) / 2.0f);
    Point mid_bc(mid_bc_x, mid_bc_y);
    test_point("on edge BC", a, b, c, mid_bc);
    
    Fixed mid_ca_x = Fixed((cx.toFloat() + ax.toFloat()) / 2.0f);
    Fixed mid_ca_y = Fixed((cy.toFloat() + ay.toFloat()) / 2.0f);
    Point mid_ca(mid_ca_x, mid_ca_y);
    test_point("on edge CA", a, b, c, mid_ca);

    std::cout << "\n=== Inside ===" << std::endl;
    Fixed center_x = Fixed((ax.toFloat() + bx.toFloat() + cx.toFloat()) / 3.0f);
    Fixed center_y = Fixed((ay.toFloat() + by.toFloat() + cy.toFloat()) / 3.0f);
    Point center(center_x, center_y);
    test_point("inside (center)", a, b, c, center);

    Fixed inside1_x(-2.0f), inside1_y(0.5f);
    Point inside1(inside1_x, inside1_y);
    test_point("inside1", a, b, c, inside1);

    std::cout << "\n=== Outside ===" << std::endl;
    Fixed far_x(10.0f), far_y(10.0f);
    Point far(far_x, far_y);
    test_point("Far", a, b, c, far);

    Fixed outside1_x(-4.0f), outside1_y(0.0f);
    Point outside1(outside1_x, outside1_y);
    test_point("Outside near", a, b, c, outside1);

    Fixed ex(1.27f), ey(1.3f);
    Point e(ex, ey);
    test_point("outside2", a, b, c, e);

    std::cout << "\n=== Near edge ===" << std::endl;
    Fixed near_edge_x(-3.5f), near_edge_y(1.0f);
    Point near_edge(near_edge_x, near_edge_y);
    test_point("Near edge (inside)", a, b, c, near_edge);

    Fixed near_edge_out_x(-3.5f), near_edge_out_y(-2.77f);
    Point near_edge_out(near_edge_out_x, near_edge_out_y);
    test_point("Near edge (outside)", a, b, c, near_edge_out);

    return 0;
}