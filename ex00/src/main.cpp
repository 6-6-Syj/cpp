/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/13 10:54:33 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

static void isHeaderOk(std::string &line)
{
	std::istringstream hss(line);
	std::string date;
	std::string pipe;
	std::string value;

	hss >> std::ws >> date >> pipe >> value;
	if (date != "date" || pipe != "|" || value != "value")
		throw std::runtime_error("incorrect header");
}

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("could not open file");

		std::ifstream file(av[1]);

		if (!file.is_open())
			throw std::runtime_error("could not open file '" +
									 static_cast<std::string>(av[1]) + "'");

		std::string line;
		std::getline(file, line);

		isHeaderOk(line);

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
				std::cout << "Error: " << e.what() << std::endl;
			}

			// if (!btc.fillMap(line))
			// {
			//     std::cout << "OUPS: " << line << std::endl;
			// }
		}

		file.close();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}