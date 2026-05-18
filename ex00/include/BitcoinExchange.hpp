/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:41 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 16:27:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _dataBase;
	
	bool isValidDate(int year, int month, int day);
	std::string getDate(std::istringstream &iss);
	double getValue(std::istringstream &iss);

	void loadDB();
	double getRate(const std::string &date) const;

public:
	BitcoinExchange();
	~BitcoinExchange();

	void fillMap(const std::string &s);
	void isHeaderOk(std::string &line);
};