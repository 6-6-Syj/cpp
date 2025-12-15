/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:58 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/15 19:50:03 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-\
special-ketchup burger. I really do!"
			  << std::endl
			  << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You didn't put \
enough bacon in my burger! If you did, I wouldn't be asking for more!"
			  << std::endl
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. I've been coming for\
years, whereas you started working here just last month."
			  << std::endl
			  << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

Command getEnumFromString(const std::string &s)
{
	typedef std::map<std::string, Command> MapCmd;
	MapCmd cmds;
	if (cmds.empty())
	{
		cmds["DEBUG"] = DEBUG;
		cmds["INFO"] = INFO;
		cmds["WARNING"] = WARNING;
		cmds["ERROR"] = ERROR;
	}

	MapCmd::const_iterator it = cmds.find(s);
	if (it != cmds.end())
		return it->second;
	return UNKNOWN;
}

void Harl::complain(const std::string &level)
{
	switch (getEnumFromString(level))
	{
	case DEBUG:
		debug();
	case INFO:
		info();
	case WARNING:
		warning();
	case ERROR:
		error();
		break;
	case UNKNOWN:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}