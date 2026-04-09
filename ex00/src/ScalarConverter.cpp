/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:07 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 12:22:59 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

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

void printOverflow(const std::string &input)
{
	if (input.find('-') != std::string::npos)
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
}

bool containsDigit(const std::string &s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (std::isdigit(static_cast<char>(s[i])))
			return true;
	}
	return false;
}

bool isSpec(const std::string &s)
{
	if (s == "inf" || s == "inff" || s == "+inf" ||
		s == "+inff" || s == "-inf" || s == "-inff" || s == "nan" || s == "nanf")
		return true;
	else
		return false;
}

bool hasDup(const std::string &s)
{
    const char symbols[] = {'+', '-', '.', 'f'};
    size_t nb = sizeof(symbols) / sizeof(symbols[0]);

    for (size_t sym = 0; sym < nb; ++sym)
    {
        char c = symbols[sym];
        int count = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                count++;
        }
        if (count >= 2)
            return true;
    }
    return false;
}

type getType(const std::string &input)
{
	if (isSpec(input))
		return SPECIAL;
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;

	int start = 0;
	if (input[0] == '+' || input[0] == '-')
   		start = 1;

	if (input.find_first_not_of("0123456789.f", start) != std::string::npos)
		return INVALID;
	
	if (hasDup(input))
		return INVALID;
	
	if (input.find('.') != std::string::npos)
	{
		if (input.rfind('f') != std::string::npos)
			return FLOAT;
		else
			return DOUBLE;
	}
	else
		return INT;
}

void ScalarConverter::convert(const std::string &input)
{
	type eType = getType(input);

	case ()
	std::cout.unsetf(std::ios::showpoint);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	bool charPossible = true;
	bool intPossible = true;
	bool floatPossible = true;
	bool doublePossible = true;

	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		c = input[0];
		d = static_cast<double>(c);
		f = static_cast<float>(c);
		i = static_cast<int>(c);

		printChar(c, charPossible);
		printInt(i, intPossible);
		printFloat(f, floatPossible);
		printDouble(d, doublePossible);
		return;
	}

	if (!containsDigit(input) && input.length() != 1)
	{
		if (isSpec(input))
		{
			if (input == "inf" || input == "+inf" ||
				input == "inff" || input == "+inff")
				d = std::numeric_limits<double>::infinity();
			else if (input == "-inf" || input == "-inff")
				d = -std::numeric_limits<double>::infinity();
			else if (input == "nan" || input == "nanf")
				d = std::numeric_limits<double>::quiet_NaN();

			f = static_cast<float>(d);
			charPossible = false;
			intPossible = false;

			printChar(c, charPossible);
			printInt(i, intPossible);
			printFloat(f, floatPossible);
			printDouble(d, doublePossible);
		}
		else
		{
			printChar(c, false);
			printInt(i, false);
			printFloat(f, false);
			printDouble(d, false);
		}
		return;
	}

	std::istringstream iss(input);
	iss >> d;

	if (iss.fail() || !iss.eof())
	{
		printChar(c, false);
		printInt(i, false);
		printOverflow(input);
		return;
	}

	f = static_cast<float>(d);

	if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
		d < static_cast<double>(std::numeric_limits<int>::min()))
		intPossible = false;
	else
		i = static_cast<int>(d);

	if (d > 127.0 || d < 0.0)
		charPossible = false;
	else
	{
		c = static_cast<char>(d);
		if (!std::isprint(c))
			charPossible = false;
	}

	printChar(c, charPossible);
	printInt(i, intPossible);
	printFloat(f, floatPossible);
	printDouble(d, doublePossible);
}