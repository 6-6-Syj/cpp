/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:01:03 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 15:35:54 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "iostream"
#include "sstream"
#include "limits"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: ./PmergeMe \"1 5 4 2\"" << std::endl;
		return 1;
	}
	else if (ac == 2)
	{
		std::cerr << "Need atleast 2 values" << std::endl;
		return 1;
	}

	try
	{
		for (int i = 1; av[i]; i++)
		{
			std::istringstream arg(av[i]);
			std::string err(av[i]);
			double d;

			if (!(arg >> d))
				throw std::out_of_range("'" + err + "' must be an int");

			if (d > static_cast<double>(std::numeric_limits<int>::max()))
				throw std::out_of_range("'" + err + "' is higher than INT_MAX");

			if (d < 0)
				throw std::out_of_range("'" + err + "' must be a positive value");
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error:\n" << e.what() << std::endl;
	}
	
	return 0;
}