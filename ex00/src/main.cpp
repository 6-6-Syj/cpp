/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 13:57:09 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void testChars()
{
    std::cout << "\nSingle char:" << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;
    ScalarConverter::convert("Z");
    std::cout << std::endl;
    ScalarConverter::convert("$");
}

void testInts()
{
    std::cout << "\nIntegers:" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    ScalarConverter::convert("+42");
    std::cout << std::endl;
    ScalarConverter::convert("33");
    std::cout << std::endl;
    ScalarConverter::convert("2147483647"); // INT_MAX
    std::cout << std::endl;
    ScalarConverter::convert("-2147483648"); // INT_MIN
    std::cout << std::endl;
    ScalarConverter::convert("2147483648"); // INT_MAX + 1 -> inf
    std::cout << std::endl;
    ScalarConverter::convert("9223372036854775807");
}

void testFloats()
{
    std::cout << "\nFloats:" << std::endl;
    ScalarConverter::convert("0.0f");
    std::cout << std::endl;
    ScalarConverter::convert("12.01f");
    std::cout << std::endl;
    ScalarConverter::convert("-42.21f");
    std::cout << std::endl;
    ScalarConverter::convert("1.79e38f"); // FLT_MAX
    std::cout << std::endl;
    ScalarConverter::convert("1.8e315f");
}

void testDoubles()
{
    std::cout << "\nDoubles:" << std::endl;
    ScalarConverter::convert("0.0");
    std::cout << std::endl;
    ScalarConverter::convert("-52.42");
    std::cout << std::endl;
    ScalarConverter::convert("1.79e308"); // DBL_MAX
    std::cout << std::endl;
    ScalarConverter::convert("-1.8e308");
}

void testSpecials()
{
    std::cout << "\nSpecials:" << std::endl;
    ScalarConverter::convert("inf");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("inff");
    std::cout << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
}

void testInvalid()
{
    std::cout << "\nInvalid strings:" << std::endl;
    ScalarConverter::convert("42abc");
    std::cout << std::endl;
    ScalarConverter::convert("abc42");
    std::cout << std::endl;
    ScalarConverter::convert("42.abc");
    std::cout << std::endl;
    ScalarConverter::convert("42.42.42");
    std::cout << std::endl;
    ScalarConverter::convert("566y184");
    std::cout << std::endl;
    ScalarConverter::convert("84685 ->");
    std::cout << std::endl;
    ScalarConverter::convert("   42   ");
    std::cout << std::endl;
    ScalarConverter::convert("->");
}

void testHugeNumbers()
{
    std::cout << "\nHuge numbers:" << std::endl;
    ScalarConverter::convert("1e300");
    std::cout << std::endl;
    ScalarConverter::convert("-1e300");
    std::cout << std::endl;
    ScalarConverter::convert("654066565656654604684840684308408545406408409870098409409849849084098494094098049040981981980981981981098910919819819819189801919819019898109810981060354849040031684940351684640654064660446046054600464600546564546046406456406048046808408400000000000000000000000000000089409849409494980984090494094409449498494984984949849804984098494098498498494949498498498409498094984984984098498040984094984980498498409840984984094098498409840984984940940944994984940984900.0789084908409840949840");
}

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

    // testChars();
    // testInts();
    // testFloats();
    // testDoubles();
    // testSpecials();
    // testInvalid();
    testHugeNumbers();

    return 0;
}