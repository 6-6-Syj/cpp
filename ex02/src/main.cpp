/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 09:38:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <stdlib.h>

int main()
{
    const int MAX_VAL = 1000;
    
    Array<int> numbers(MAX_VAL);
    Array<int> assign(MAX_VAL / 2);

    const Array<int> constnumbers(MAX_VAL);

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        int value = rand();
        numbers[i] = value;
    }

    Array<int> copy(numbers);
    assign = numbers;

    // for (int i = 0; i < MAX_VAL; i++)
    //     std::cout << "[" << i << "]: " << assign[i] << std::endl;
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != copy[i] || numbers[i] != assign[i])
        {
            std::cout << "copy/assignment failed at " << i << std::endl;
            return 1;
        }
    }

    numbers[0] = 42;
    if (copy[0] == numbers[0] || assign[0] == numbers[0])
    {
        std::cout << "deep copy failed" << std::endl;
        return 1;
    }
    
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Index: " << e.what() << '\n';
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Index: " << e.what() << '\n';
    }

    try
    {
        constnumbers[MAX_VAL];
    }
    catch(const std::exception& e)
    {
        std::cout << "Index: " << e.what() << '\n';
    }
    
    return 0;
}