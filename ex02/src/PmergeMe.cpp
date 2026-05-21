/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:08:16 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/21 15:56:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "sstream"
#include "limits"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}



// ########################################

void parse(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream arg(av[i]);
		std::string err(av[i]);
		double d;
	
		if (!(arg >> d))
			throw std::out_of_range("'" + err + "' is not an int");
	
		if (d > static_cast<double>(std::numeric_limits<int>::max()))
			throw std::out_of_range("'" + err + "' is higher than INT_MAX");
	
		if (d < 0)
			throw std::out_of_range("'" + err + "' must be a positive value");
	}
}