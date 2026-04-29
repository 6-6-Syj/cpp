/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/29 14:08:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc <file>" << std::endl;
		return 0 ;
 	}
	 
	std::ifstream file(av[1]);
	
	if (!file.is_open())
	{
		std::cout << "\"" << av[1] << "\" not found !" << std::endl;
		return 0 ;
	}

	bool header = false;
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date | value")
		{
			if (header)
			{
				std::cout << "ERROR" << std::endl;
				return 0 ;
			}
			else
				header = true ;
		}
		std::cout << line << std::endl;
	}
		
	file.close();
	return 0;
}