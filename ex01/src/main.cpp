/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/21 15:30:44 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void testRange(Span& sp)
{
    Span sp3 = Span(99999);

    try
    {
        for (int i = 0; (sp3.getVec().size() + sp.getVec().size()) < sp3.getVec().capacity(); i++)
            sp3.addAllNumbers(sp.getVec());
        sp3.printVec();
        sp3.addAllNumbers(sp.getVec());
    }
    catch(const std::exception& e)
    {
        std::cout << "addAllNumbers: " << e.what() << std::endl;
    }
}

void testOverflow()
{
    Span sp(2);

    sp.addNumber(__INT_MAX__);
    sp.addNumber(-__INT_MAX__ - 1);
        
    try
    {
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;

        sp.getVec().clear(); // because getVec not const;
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testSubject(Span& sp)
{
    try
    {
        sp.addNumber(-5);
        sp.addNumber(11);
        sp.addNumber(-17);
        sp.addNumber(14);
        sp.addNumber(6);
        sp.addNumber(0);
    }
    catch (const std::exception &e)
    {
        std::cout << "addNumber: " << e.what() << std::endl;
    }
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest: " << sp.longestSpan() << std::endl;
}

int main()
{
    Span sp = Span(5);

    testSubject(sp);
    testOverflow();
    testRange(sp);

    return 0;
}