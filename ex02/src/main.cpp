/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:33 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 13:48:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    Fixed const c(Fixed(3.1459f) * Fixed(3.99999f));
    Fixed const d(Fixed(3.1459f) * Fixed(5.127f));

    // Basic output and increment
    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "--a = " << --a << std::endl << std::endl;

    // Comparison operator
    std::cout << "a = " << a << " | b = " << b << std::endl;
    std::cout << std::boolalpha;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl << std::endl;

    // Arithmetic operator
    std::cout << "a = " << a << " | b = " << b << " | c = "
              << c << " | d = " << d << std::endl;
    Fixed add = b + c;
    Fixed sub = b - c;
    Fixed mul = b * c;
    Fixed div = b / Fixed(2);

    std::cout << "\nb + c = " << add << std::endl;
    std::cout << "b - c = " << sub << std::endl;
    std::cout << "b * c = " << mul << std::endl;
    std::cout << "b / 2 = " << div << std::endl << std::endl;

    // Using min and max
    std::cout << "(const) min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "(const) max(a, b) = " << Fixed::max(a, b) << std::endl;

    Fixed x = 2;
    Fixed y = 23;
    
    std::cout << "min(c, d) = " << Fixed::min(x, y) << std::endl;
    std::cout << "max(c, b) = " << Fixed::max(x, y) << std::endl;
    
    return 0;
}