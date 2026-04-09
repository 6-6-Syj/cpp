/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:06:13 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/09 12:20:55 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " [arg]" << std::endl;
        return 1;
    }

    const std::string input = av[1];

    std::cout << "Input: \"" << input << "\"" << std::endl;
    ScalarConverter::convert(input);
    std::cout << std::endl;

    // std::cout << "\nSingle char:" << std::endl;
    // ScalarConverter::convert("a");
    // ScalarConverter::convert("0");
    // ScalarConverter::convert("Z");

    // std::cout << "\nIntegers:" << std::endl;
    // ScalarConverter::convert("0");
    // ScalarConverter::convert("42");
    // ScalarConverter::convert("-42");
    // ScalarConverter::convert("2147483647");   // INT_MAX
    // ScalarConverter::convert("-2147483648");  // INT_MIN
    // ScalarConverter::convert("2147483648");   // INT_MAX + 1 -> inf / impossible ?
    // ScalarConverter::convert("9223372036854775807");

    // std::cout << "\nHuge numbers (should give inf):" << std::endl;
    // ScalarConverter::convert("1e300");
    // ScalarConverter::convert("-1e300");
    // ScalarConverter::convert("654066565656654604684840684308408545406408409870098409409849849084098494094098049040981981980981981981098910919819819819189801919819019898109810981060354849040031684940351684640654064660446046054600464600546564546046406456406048046808408400000000000000000000000000000089409849409494980984090494094409449498494984984949849804984098494098498498494949498498498409498094984984984098498040984094984980498498409840984984094098498409840984984940940944994984940984900.0789084908409840949840");

    // std::cout << "\nFloats:" << std::endl;
    // ScalarConverter::convert("0.0");
    // ScalarConverter::convert("42.21f");
    // ScalarConverter::convert("-42.21f");
    // ScalarConverter::convert("1.79e38f");    // FLT_MAX
    // ScalarConverter::convert("1.8e38f");

    // std::cout << "\nDoubles:" << std::endl;
    // ScalarConverter::convert("0.0");
    // ScalarConverter::convert("42.42");
    // ScalarConverter::convert("-42.42");
    // ScalarConverter::convert("1.79e308");    // DBL_MAX
    // ScalarConverter::convert("1.8e308");

    // std::cout << "\nSpecials:" << std::endl;
    // ScalarConverter::convert("inf");
    // ScalarConverter::convert("+inf");
    // ScalarConverter::convert("-inf");
    // ScalarConverter::convert("inff");
    // ScalarConverter::convert("+inff");
    // ScalarConverter::convert("-inff");
    // ScalarConverter::convert("nan");
    // ScalarConverter::convert("nanf");

    // std::cout << "\nInvalid strings (should be impossible):" << std::endl;
    // ScalarConverter::convert("abc");
    // ScalarConverter::convert("pouet");
    // ScalarConverter::convert("42abc");
    // ScalarConverter::convert("abc42");
    // ScalarConverter::convert("42.abc");
    // ScalarConverter::convert("42..42");
    // ScalarConverter::convert("566184..498498");
    // ScalarConverter::convert("84685 ->");
    // ScalarConverter::convert("   42   ");
    // ScalarConverter::convert("");
    // ScalarConverter::convert("...");
    // ScalarConverter::convert("->");
    // ScalarConverter::convert("42.42.42");

    return 0;
}