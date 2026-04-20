/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/20 09:40:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(-5);
    vec.push_back(3);
    vec.push_back(7);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::deque<int> deq;
    deq.push_back(0);
    deq.push_back(__INT_MAX__);

    try
    {
        easyfind(vec, -5);
    }
    catch (const std::exception &e)
    {
        std::cout << "vec: " << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 40);
    }
    catch (const std::exception &e)
    {
        std::cout << "lst: " << e.what() << std::endl;
    }
    
    try
    {
        easyfind(deq, 1);
    }
    catch (const std::exception &e)
    {
        std::cout << "deq: " << e.what() << std::endl;
    }

    return 0;
}
