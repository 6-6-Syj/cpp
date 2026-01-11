/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:58 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 15:54:08 by jmagand          ###   ########.fr       */
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

const array Harl::_commands[] = {
	{"DEBUG", DEBUG},
	{"INFO", INFO},
	{"WARNING", WARNING},
	{"ERROR", ERROR}
};

enumCommand Harl::getEnumFromString(const std::string &s) const
{
    for (int i = 0; i < UNKNOWN; i++)
    {
        if (s == _commands[i].name)
            return _commands[i].command;
    }
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