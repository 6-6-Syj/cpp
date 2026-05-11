/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:10:41 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/11 14:46:58 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, int> _map;

public:
	BitcoinExchange();
	~BitcoinExchange();

	bool fillMap(const std::string &s);
};