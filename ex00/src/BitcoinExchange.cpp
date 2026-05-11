/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/11 16:34:03 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

static bool isValidDate(int year, int month, int day)
{
	static const int normalDays[] = {31, 28, 31, 30, 31, 30,
									 31, 31, 30, 31, 30, 31};

	bool isLeapYear = false;
	if (year % 400 == 0)
		isLeapYear = true;
	else if (year % 100 == 0)
		isLeapYear = false;
	else if (year % 4 == 0)
		isLeapYear = true;

	int maxDays;
	if (month == 2 && isLeapYear)
		maxDays = 29;
	else if (month >= 1 && month <= 12)
		maxDays = normalDays[month - 1];
	else
		maxDays = 0;

	if (day > maxDays)
		return false;

	return true;
}

static std::string getDate(std::istringstream &iss)
{
	std::string date;

	iss >> std::ws;
	std::getline(iss, date, ' ');

	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_last_not_of(" \t") + 1);

	if (date.length() != 10)
		throw std::runtime_error("Error: bad input => " + date);

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw std::runtime_error("Error: bad input => " + date);
		}
		else if (!std::isdigit(static_cast<unsigned char>(date[i])))
			throw std::runtime_error("Error: bad input => " + date);
	}

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year;
	int month;
	int day;

	std::istringstream yss(yearStr);
	std::istringstream mss(monthStr);
	std::istringstream dss(dayStr);

	if (!(yss >> year) || !(mss >> month) || !(dss >> day) || year < 2009 ||
		month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + date);

	if (!isValidDate(year, month, day))
		throw std::runtime_error("Error: invalid date => " + date);
		
	return date;
}

static double getValue(std::istringstream &iss)
{
	std::string valueStr;
	std::getline(iss, valueStr);

	valueStr.erase(0, valueStr.find_first_not_of(" \t"));
	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

	double value;
	std::istringstream valIss(valueStr);

	if (!(valIss >> value) || !valIss.eof())
		throw std::runtime_error("Error: not a number => " + valueStr);

	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");

	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");

	return value;
}

bool BitcoinExchange::fillMap(const std::string &s)
{
	if (s.empty() || s.find_first_not_of(" \t\r\n") == std::string::npos)
		return true;

	std::istringstream iss(s);
	std::string date = getDate(iss);

	std::string pipe;
	std::getline(iss, pipe, '|');

	double value = getValue(iss);



	_map[date] = value;
	return true;
}
