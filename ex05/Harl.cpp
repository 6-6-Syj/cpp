/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:58 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/15 18:48:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-\
special-ketchup burger. I really do!"
			  << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put \
enough bacon in my burger! If you did, I wouldn't be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for\
years, whereas you started working here just last month."
			  << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string strings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	size_t size = sizeof(strings) / sizeof(strings[0]);
	for (size_t i = 0; i < size; i++)
	{
		if (level == strings[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Command not recognized" << std::endl;
}