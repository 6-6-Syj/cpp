/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:08:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 11:55:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &copy) : _values(copy._values) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_values = other._values;
	return *this;
}

RPN::~RPN() {}

void RPN::process(std::string &arg)
{
	std::istringstream iss(arg);
	std::string tmp;

	while (iss >> tmp)
	{
		if (tmp == "+" || tmp == "-" || tmp == "/" || tmp == "*")
		{
			if (_values.size() < 2)
				throw std::runtime_error("Invalid input");

			int b = _values.top();
			_values.pop();
			int a = _values.top();
			_values.pop();

			if (tmp == "+")
				_values.push(a + b);
			else if (tmp == "-")
				_values.push(a - b);
			else if (tmp == "*")
				_values.push(a * b);
			else if (tmp == "/")
			{
				if (b == 0)
					throw std::runtime_error("'x / 0' is impossible");
				_values.push(a / b);
			}
		}
		else
		{
			std::istringstream intss(tmp);
			int x;
			intss >> x;
			_values.push(x);
		}
	}

	if (_values.size() != 1)
		throw std::runtime_error("Invalid input");

	std::cout << _values.top() << std::endl;
	_values.pop();
}

void isValidExpression(std::string &arg)
{
	static const std::string available = "0123456789 +-/*";

	std::string::size_type invalid = arg.find_first_not_of(available);
	if (invalid != std::string::npos)
		throw std::runtime_error("Invalid char used: " + std::string(1, arg[invalid]));

	std::istringstream iss(arg);
	std::string tmp;

	while (iss >> tmp)
	{
		if (tmp.length() != 1)
			throw std::runtime_error("Invalid input: " + tmp);
	}
}
