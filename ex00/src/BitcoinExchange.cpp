/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 16:28:45 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::isValidDate(int year, int month, int day)
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

std::string BitcoinExchange::getDate(std::istringstream &iss)
{
	std::string date;
	std::getline((iss >> std::ws), date, ' ');

	date.erase(date.find_last_not_of(" \t") + 1);

	if (date.length() != 10)
		throw std::runtime_error("bad input => " + date);

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw std::runtime_error("bad input => " + date);
		}
		else if (!std::isdigit(static_cast<unsigned char>(date[i])))
			throw std::runtime_error("bad input => " + date);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || !isValidDate(year, month, day))
		throw std::runtime_error("invalid date => " + date);

	return date;
}

double BitcoinExchange::getValue(std::istringstream &iss)
{
	std::string valueStr;
	std::getline((iss >> std::ws), valueStr);

	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

	std::istringstream vss(valueStr);
	double value;

	if (!(vss >> value) || !vss.eof())
		throw std::runtime_error("not a number => " + valueStr);

	if (value < 0)
		throw std::runtime_error("not a positive number.");
	else if (value > 1000)
		throw std::runtime_error("too large number.");

	return value;
}

void BitcoinExchange::loadDB()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw std::runtime_error("could not open database file");

	std::string line;
	std::getline(file, line);
	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rate;

		if (std::getline(ss, date, ','))
		{
			if (std::getline(ss, rate))
				_dataBase[date] = std::atof(rate.c_str());
		}
	}
	file.close();
}

double BitcoinExchange::getRate(const std::string &date) const
{
	double rate = -1;
	for (std::map<std::string, double>::const_iterator it = _dataBase.begin();
		 it != _dataBase.end(); ++it)
	{
		if (date > it->first)
			rate = it->second;
		else
			break ;
	}
	return rate;
}


/* Pas bon le fillmap ! */
/* void BitcoinExchange::fillMap(const std::string &s)
{
	if (s.empty() || s.find_first_not_of(" \t\r\n") == std::string::npos)
		return;

	std::istringstream iss(s);
	std::string date = getDate(iss);

	std::string pipe;
	if (!(iss >> pipe) || pipe != "|")
		throw std::runtime_error("bad input");

	double value = getValue(iss);

	// _dataBase[date] = value;
} */

void BitcoinExchange::isHeaderOk(std::string &line)
{
	std::istringstream hss(line);
	std::string date;
	std::string pipe;
	std::string value;

	if (!(hss >> date >> pipe >> value) || date != "date" || pipe != "|" || value != "value")
		throw std::runtime_error("incorrect header");
}