/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 11:38:28 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

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

		BitcoinExchange btc;
		
		btc.isHeaderOk(line);

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