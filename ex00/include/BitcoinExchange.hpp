/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:41 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/27 16:18:09 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _dataBase;

	bool isValidDate(int year, int month, int day) const;

	std::string getDate(std::istringstream &iss) const;
	double getValue(std::istringstream &iss) const;

	double getRate(const std::string &date) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void exchange(std::ifstream &file) const;
	void loadDB();
};

void isHeaderOk(std::ifstream &file, std::string arg);
