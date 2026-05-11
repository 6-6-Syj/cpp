/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/11 15:43:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream file(av[1]);

	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(file, line);

	std::istringstream iss(line);

	std::string date;
	std::string pipe;
	std::string value;
	
	iss >> std::ws >> date >> pipe >> value;

	if (date != "date" || pipe != "|" || value != "value")
	{
		std::cout << "Error: incorrect header." << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	while (getline(file, line))
	{
		// std::cout << line << std::endl;

		try
		{
			btc.fillMap(line);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}

		// if (!btc.fillMap(line))
		// {
		//     std::cout << "OUPS: " << line << std::endl;
		// }
	}

	file.close();
	return 0;
}