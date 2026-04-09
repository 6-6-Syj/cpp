/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:12:46 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:13:07 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

void printChar(const char &c, bool possible)
{
	std::cout << "char: ";
	if (!possible)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
}

void printInt(const int &i, bool possible)
{
	std::cout << "int: ";
	if (!possible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void printFloat(const float &f, bool possible)
{
	std::cout << "float: ";
	if (!possible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void printDouble(const double &d, bool possible)
{
	std::cout << "double: ";
	if (!possible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}

void printAll(char c, int i, float f, double d,
			  bool charPossible, bool intPossible, bool floatPossible, bool doublePossible)
{
	printChar(c, charPossible);
	printInt(i, intPossible);
	printFloat(f, floatPossible);
	printDouble(d, doublePossible);
}