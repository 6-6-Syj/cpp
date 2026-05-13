/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/13 12:05:45 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

static bool isValidDate(int year, int month, int day)
{
	static const int normalDays[] = {0, 31, 28, 31, 30, 31, 30,
									 31, 31, 30, 31, 30, 31};

	bool leapYear = false;
	
	if (year % 400 == 0)
		leapYear = true;
	else if (year % 100 == 0)
		leapYear = false;
	else if (year % 4 == 0)
		leapYear = true;

	int maxDays = 0;

	if (month == 2 && leapYear)
		maxDays = 29;
	else if (month >= 1 && month <= 12)
		maxDays = normalDays[month];

	if (day > maxDays)
		return false;
	return true;
}

static std::string getDate(std::istringstream &iss)
{
	std::string date;

	std::getline((iss >> std::ws), date, ' ');


	/* TODO: Correct this. JEN SUIS LA */
	/* 	 2011-01-03		 	  | 	  	 	3	  	 		 	 	 	  */
	if (date.length() != 10)
	{
		// while (date.length() != 10)
		// date.erase();
		std::cout << "'" << date << "'" << std::endl;
		throw std::runtime_error("1bad input => " + date);
	}

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw std::runtime_error("2bad input => " + date);
		}
		else if (!std::isdigit(static_cast<unsigned char>(date[i])))
			throw std::runtime_error("3bad input => " + date);
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
		throw std::runtime_error("bad input => " + date);

	if (!isValidDate(year, month, day))
		throw std::runtime_error("invalid date => " + date);
		
	return date;
}

static double getValue(std::istringstream &iss)
{
	std::string valueStr;
	double value;

	std::getline((iss >> std::ws), valueStr);
	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

	std::istringstream vss(valueStr);

	if (!(vss >> value) || !vss.eof())
		throw std::runtime_error("not a number => " + valueStr);

	if (value < 0)
		throw std::runtime_error("not a positive number.");

	if (value > 1000)
		throw std::runtime_error("too large a number.");

	return value;
}

void BitcoinExchange::fillMap(const std::string &s)
{
	if (s.empty() || s.find_first_not_of(" \t\r\n") == std::string::npos)
		return ;

	std::istringstream iss(s);
	std::string date = getDate(iss);

	std::string pipe;
	std::getline(iss, pipe, '|');

	double value = getValue(iss);

	_map[date] = value;
}
