/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:37:00 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 15:54:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum enumCommand
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

struct array
{
	const char *name;
	enumCommand command;
};

class Harl
{
private:
	void debug();
	void info();
	void warning();
	void error();

	static const array _commands[];
	enumCommand getEnumFromString(const std::string &s) const;

public:
	void complain(const std::string &level);
};