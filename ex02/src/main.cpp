/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:01:03 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/28 14:13:07 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "iostream"
#include <sys/time.h>
#include <set>

static void parse(int ac, char **av)
{
    std::set<int> seen;

    for (int i = 1; i < ac; i++)
    {
        std::istringstream arg(av[i]);
        std::string err(av[i]);
        double d;

        if (!(arg >> d) || err.find('.') != std::string::npos)
            throw std::out_of_range("'" + err + "' is not an int");

        if (d > static_cast<double>(std::numeric_limits<int>::max()))
            throw std::out_of_range("'" + err + "' is higher than INT_MAX");

        if (d < 0)
            throw std::out_of_range("'" + err + "' must be a positive value");

        int value = static_cast<int>(d);
        if (seen.find(value) != seen.end())
            throw std::out_of_range("Duplicate value: '" + err + "'");
			
        seen.insert(value);
    }
}

static long getUs()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000L + tv.tv_usec;
}

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
			return 1;
		}

		parse(ac, av);

		std::cout << "Before:\n\t";
		for (int i = 1; i < ac; i++)
			std::cout << " " << av[i];
		std::cout << std::endl << std::endl;

		PmergeMe<std::vector<int> > pmerge_vec;

		long t0 = getUs();
		pmerge_vec.process(ac - 1, av);
		long vecUs = getUs() - t0;

		PmergeMe<std::deque<int> > pmerge_deq;

		t0 = getUs();
		pmerge_deq.process(ac - 1, av);
		long deqUs = getUs() - t0;

		std::cout << "After:\n\t";
		for (size_t i = 0; i < pmerge_vec.getContainer().size(); i++)
			std::cout << " " << pmerge_vec.getContainer()[i];
		std::cout << std::endl << std::endl;

		std::cout << "Time to process a range of " << (ac - 1)
				  << " elements with std::vector : " << vecUs << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1)
				  << " elements with std::deque  : " << deqUs << " us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error:\n"
				  << e.what() << std::endl;
		return 1;
	}

	return 0;
}