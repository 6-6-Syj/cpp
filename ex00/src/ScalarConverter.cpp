/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:07 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:13:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"
#include "print.h"
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

static type getType(const std::string &input)
{
	if (isSpec(input))
		return SPECIAL;
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;

	int start = 0;
	if (input[0] == '+' || input[0] == '-')
		start = 1;

	if (input.find_first_not_of("0123456789.fe", start) != std::string::npos)
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

	type eType = getType(input);

	switch (eType)
	{
	case CHAR:
	{
		c = input[0];
		d = static_cast<double>(c);
		f = static_cast<float>(c);
		i = static_cast<int>(c);
		printAll(c, i, f, d, charPossible, intPossible, floatPossible, doublePossible);
		break;
	}

	case SPECIAL:
	{
		if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
			d = std::numeric_limits<double>::infinity();
		else if (input == "-inf" || input == "-inff")
			d = -std::numeric_limits<double>::infinity();
		else if (input == "nan" || input == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();

		f = static_cast<float>(d);
		charPossible = false;
		intPossible = false;

		printAll(c, i, f, d, charPossible, intPossible, floatPossible, doublePossible);
		break;
	}

	case INT:
	case FLOAT:
	case DOUBLE:
	{
		std::string tmp = input;
		char c = tmp[tmp.length() - 1];
		
		if (c == 'f' || c == 'F')
			tmp.erase(tmp.length() - 1, 1);

		std::istringstream iss(tmp);
		iss >> d;

		if (iss.fail() || !iss.eof())
		{
			if (!tmp.empty() && tmp[0] == '-')
			{
				d = -std::numeric_limits<double>::infinity();
				f = -std::numeric_limits<float>::infinity();			
			}
			else
			{
				d = std::numeric_limits<double>::infinity();
				f = std::numeric_limits<float>::infinity();
			}
			
			printAll(c, i, f, d, false, false, floatPossible, doublePossible);
			return;
		}

		double DBL_MAX = std::numeric_limits<double>::max();
		double DBL_MIN = -DBL_MAX;

		if (d > DBL_MAX || d < DBL_MIN)
		{
			if (d > 0)
				d = std::numeric_limits<double>::infinity();
			else
				d = -std::numeric_limits<double>::infinity();
		}

		float FLT_MAX = std::numeric_limits<float>::max();
		float FLT_MIN = -FLT_MAX;

		if (d > FLT_MAX)
			f = std::numeric_limits<float>::infinity();
		else if (d < FLT_MIN)
			f = -std::numeric_limits<float>::infinity();
		else
			f = static_cast<float>(d);

		if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
			d < static_cast<double>(std::numeric_limits<int>::min()))
			intPossible = false;
		else
			i = static_cast<int>(d);

		if (d > 127 || d < 0)
			charPossible = false;
		else
			c = static_cast<char>(d);
		printAll(c, i, f, d, charPossible, intPossible, floatPossible, doublePossible);
		break;
	}

	case INVALID:
	default:
	{
		printAll(c, i, f, d, false, false, false, false);
		break;
	}
	}
}