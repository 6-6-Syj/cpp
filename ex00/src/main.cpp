/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 14:17:37 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "tests.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " [arg]" << std::endl;
        return 1;
    }

    const std::string input = av[1];

    if (input.empty())
    {
        std::cout << "Input cannot be empty." << std::endl;
        return 1;
    }

    ScalarConverter::convert(input);
    testChars();
    testInts();
    testFloats();
    testDoubles();
    testSpecials();
    testInvalid();
    testHugeNumbers();

    return 0;
}