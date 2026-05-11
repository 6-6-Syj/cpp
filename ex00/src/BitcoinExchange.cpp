/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/11 14:40:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::fillMap(std::string &s)
{
	std::istringstream iss(s);
	std::string date;
	std::string value;

	if (!std::getline(iss >> std::ws, date, '|') ||
		!std::getline(iss >> std::ws, value))
	{
		throw "Error: bad input => ";
	}
	
	if (date.length() != 11)
        return false;

	for (size_t i = 0; i < date.length() - 1; i++)
	{
		if ((i == 4 && date[i] != '-') || (i == 7 && date[i] != '-'))
			return false;
		else if (i != 4 && i != 7)
		{
			if (!std::isdigit(date[i]))
			{
				std::cout << date[i] << std::endl;
				return false;	
			}
		}
	}

	return true;
}
