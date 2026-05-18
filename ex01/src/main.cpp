/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 16:09:42 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.h"

int main(void)
{
    {
        std::cout << "=== TEST INT ===" << std::endl;
        const int intArray[4] = {0, 1, 2, 3};
        size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
        ::iter(intArray, intLength, print);
        std::cout << std::endl;
    }

    {
        std::cout << "=== TEST DOUBLE ===" << std::endl;
        double doubleArray[3] = {3.14, 2.71, 1.41};
        size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
        ::iter(doubleArray, doubleLength, print);
        std::cout << std::endl;
    }

    {
        std::cout << "=== TEST STRING ===" << std::endl;
        std::string stringArray[4] = {"one", "two", "three", "four"};
        size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
        ::iter(stringArray, stringLength, print);
        std::cout << std::endl;
    }
    
    {
        std::cout << "=== TEST BOOL ===" << std::endl;
        const bool boolArray[5] = {true, false, true, false, true};
        size_t boolLength = sizeof(boolArray) / sizeof(boolArray[0]);
        ::iter(boolArray, boolLength, print);
        std::cout << std::endl;
    }

    {
        std::cout << "=== TEST CHAR ===" << std::endl;
        char charArray[6] = {'H', 'e', 'l', 'l', 'o', '!'};
        size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
        ::iter(charArray, charLength, print);
        std::cout << std::endl;
    }

    return 0;
}