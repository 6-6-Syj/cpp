/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:33 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/17 17:21:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(3.1459f) * Fixed(3.99999f));
	Fixed const d(Fixed(3.1459f) * Fixed(3.99999f));

 // Basic output and increment tests
    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "--a = " << --a << std::endl;

    // Comparison operator tests
    std::cout << std::boolalpha;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    // Arithmetic operator tests
    Fixed add = b + c;
    Fixed sub = b - c;
    Fixed mul = b * c;
    Fixed div = b / Fixed(2);

    std::cout << "b + c = " << add << std::endl;
    std::cout << "b - c = " << sub << std::endl;
    std::cout << "b * c = " << mul << std::endl;
    std::cout << "b / 2 = " << div << std::endl;

    // Using min and max utilities
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(c, b) = " << Fixed::max(c, b) << std::endl;
    std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;

	return 0;
}