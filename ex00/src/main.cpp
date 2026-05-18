/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 13:52:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void)
{
    try
    {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(-5);
		vec.push_back(3);
		vec.push_back(7);
	
        std::cout << "vec: " << *easyfind(vec, -5) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
    	lst.push_back(40);
	
		std::cout << "lst: " << *easyfind(lst, 10) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
		std::deque<int> deq;
		deq.push_back(0);
		deq.push_back(__INT_MAX__);
		
        std::cout << "deq: " << *easyfind(deq, 1) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
