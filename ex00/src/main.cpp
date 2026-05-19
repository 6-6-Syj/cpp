/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/19 15:40:15 by jmagand          ###   ########.fr       */
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
		isHeaderOk(file, static_cast<std::string>(av[1]));
		
		BitcoinExchange btc;
		btc.loadDB();
		
		btc.exchange(file);

		file.close();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}