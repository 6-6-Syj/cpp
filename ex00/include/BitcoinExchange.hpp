/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:41 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 11:38:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, int> _map;
	
	double getValue(std::istringstream &iss);
	std::string getDate(std::istringstream &iss);
	bool isValidDate(int year, int month, int day);

public:
	BitcoinExchange();
	~BitcoinExchange();

	void fillMap(const std::string &s);
	void isHeaderOk(std::string &line);
};