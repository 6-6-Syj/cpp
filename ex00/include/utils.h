/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:10:37 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:20:49 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

bool isSpec(const std::string &s)
{
	if (s == "inf" || s == "inff" || s == "+inf" ||
		s == "+inff" || s == "-inf" || s == "-inff" || s == "nan" || s == "nanf")
		return true;
	else
		return false;
}

bool hasDup(const std::string &s)
{
	const char symbols[] = {'+', '-', '.', 'f', 'F'};
	size_t nb = sizeof(symbols) / sizeof(symbols[0]);

	for (size_t sym = 0; sym < nb; ++sym)
	{
		char c = symbols[sym];
		int count = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == c)
				++count;
		}
		if (count >= 2)
			return true;
	}
	return false;
}