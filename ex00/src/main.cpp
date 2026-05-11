/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:13:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/11 11:39:44 by jmagand          ###   ########.fr       */
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
		return 1;
 	}
	 
	std::ifstream file(av[1]);
	
	if (!file.is_open())
	{
		std::cout << "\"" << av[1] << "\" not found !" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(file, line);
	
    if (line != "date | value")
    {
        std::cout << "Error: incorrect header" << std::endl;
        file.close();
        return 1;
    }
    
    BitcoinExchange btc;

    while (getline(file, line))
    {
        // std::cout << line << std::endl;

        
        if (!btc.fillMap(line))
        {
            std::cout << "OUPS: " << line << std::endl;
        }
        
    }
	
		
	file.close();
	return 0;
}