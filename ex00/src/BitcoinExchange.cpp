/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/27 16:19:58 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _dataBase(copy._dataBase) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_dataBase = other._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::isValidDate(int year, int month, int day) const
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

	if (day < 1 || day > maxDays)
		return false;
	return true;
}

std::string BitcoinExchange::getDate(std::istringstream &iss) const
{
	std::string date;
	std::getline((iss >> std::ws), date, ' ');

	date.erase(date.find_last_not_of(" \t") + 1);

	if (date.empty())
		return date;
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
		throw std::runtime_error("bad input => " + date);

	return date;
}

double BitcoinExchange::getValue(std::istringstream &iss) const
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

double BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _dataBase.lower_bound(date);

	if (it != _dataBase.end() && it->first == date)
		return it->second;

	if (it == _dataBase.begin())
		throw std::runtime_error("date " + date + " is too old");

	if (it == _dataBase.end() || it->first > date)
		--it;

	return it->second;
}

void BitcoinExchange::exchange(std::ifstream &file) const
{
	std::string line, date, pipe;
	double value;

	while (getline(file, line))
	{
		try
		{
			std::istringstream iss(line);

			date = getDate(iss);
			if (date.empty())
				continue;

			iss >> pipe;

			value = getValue(iss);
			double res = getRate(date) * value;

			std::cout << date << " => " << value << " = " << res << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::loadDB()
{
	std::ifstream fileCSV("data.csv");

	if (!fileCSV.is_open())
		throw std::runtime_error("could not open database file");

	std::string line;
	while (getline(fileCSV, line))
	{
		std::stringstream ss(line);
		std::string date, rate;

		if (std::getline(ss, date, ','))
		{
			if (std::getline(ss, rate))
				_dataBase[date] = std::atof(rate.c_str());
		}
	}
	fileCSV.close();
}

void isHeaderOk(std::ifstream &file, std::string arg)
{
	if (!file.is_open())
		throw std::runtime_error("could not open file '" + arg + "'");

	std::string line, date, pipe, value;
	std::getline(file, line);
	std::istringstream hss(line);

	if (!(hss >> date >> pipe >> value) || date != "date" || pipe != "|" || value != "value")
		throw std::runtime_error("incorrect header");
}