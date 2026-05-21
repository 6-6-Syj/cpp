/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:01:03 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 15:55:45 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "iostream"

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
		parse(ac, av);
		
		PmergeMe pmerge;
		// pmerge.fill();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error:\n" << e.what() << std::endl;
	}
	
	return 0;
}